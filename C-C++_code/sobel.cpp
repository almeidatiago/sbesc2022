#include "input_Elaine.h"
#include "input_Airplane.h"
#include "input_Baboon.h"
#include "input_Peppers.h"
#include "input_Splash.h"
#include "output_Elaine.h"
// Call the Approximated Adder
#include "add16_RCA.h"
#include <stdio.h>
#include <stdlib.h>

#define HEIGHT 512
#define WIDTH 512

void sobel_filter(unsigned char in[HEIGHT][WIDTH],
                  unsigned char out[HEIGHT][WIDTH]) {
#pragma HLS function top

    // The 3x3 Sobel filters.
    const static int gx[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    const static int gy[3][3] = {{1, 2, 1}, {0, 0, 0}, {-1, -2, -1}};

    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            // Set output to 0 if the 3x3 receptive field is out of bound.
            if ((i < 1) | (i > HEIGHT - 2) | (j < 1) | (j > WIDTH - 2)) {
                out[i][j] = 0;
                continue;
            }

            // Apply the sobel filter at the current "receptive field".
            int gx_sum = 0, gy_sum = 0;
            for (int m = -1; m <= 1; m++) {
                for (int n = -1; n <= 1; n++) {
                    int pixel = in[i + m][j + n];
                    // Apply Approximated Adder
                    gx_sum = add16_RCA(gx_sum, (pixel * gx[m + 1][n + 1]));
                    // Apply Approximated Adder
                    gy_sum = add16_RCA(gy_sum, (pixel * gy[m + 1][n + 1]));
                }
            }

            gx_sum = (gx_sum < 0) ? -gx_sum : gx_sum;
            gy_sum = (gy_sum < 0) ? -gy_sum : gy_sum;

            int sum = gx_sum + gy_sum;
            sum = (sum > 255) ? 255 : sum;

            out[i][j] = (unsigned char)sum;
        }
    }
}

int main() {
    unsigned char sobel_output[HEIGHT][WIDTH];
    FILE* output;

    output = fopen("add16_RCA_output.h", "wb");
    fprintf(output, "unsigned char elaine_512_add16_RCA[512][512] = {\n");

    // Read image
    sobel_filter(Elaine_512_input, sobel_output);

    // Verify output by comparing against a golden output.
    int mismatch_count = 0;
    for (int i = 0; i < HEIGHT; i++) {
    	fprintf(output, "{");
        for (int j = 0; j < WIDTH; j++) {
        	if (j < (WIDTH - 1))
        		fprintf(output, "%d, ", sobel_output[i][j]);
        	else
        		fprintf(output, "%d", sobel_output[i][j]);
            if (sobel_output[i][j] != elaine_512_golden_output[i][j])
                mismatch_count++;
        }
        fprintf(output, "},\n");
    }
    fprintf(output, "};\n");


    if (mismatch_count == 0)
        printf("PASS!\n");
    else
        printf("FAIL with %d differences\n", mismatch_count);

    return 0;
}

