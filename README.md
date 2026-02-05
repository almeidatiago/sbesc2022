### 1. ErrorMetricsCompAdder.ipynb

* **Exact vs. Approximate Analysis**: Uses Python to compare "Exact" addition with several approximate versions.
* **Probability Mass Function (PMF)**: Generates a histogram-like chart showing the statistical distribution of errors, which is crucial for predicting how an approximate circuit will behave under different workloads.
* **Metric Comparison**: Calculates basic metrics (MAE, MSE, WCE) to rank different adder designs from the EvoApprox library.

### 2. ErrorMetricsCompLOA.ipynb

* **Lower-Part-OR Adder (LOA) Study**: Specifically focuses on the LOA architecture, where the LSBs (Least Significant Bits) are computed using a simple OR gate instead of full addition logic.
* **Configurable Approximation**: Analyzes how the error metrics scale as you increase the number of approximate bits (from LOA1 to LOA8), showing the exponential growth of error vs. the linear reduction in hardware area.

### 3. ErrorMetricsCompMult.ipynb

* **Multiplier Precision**: Similar to the adder analysis but for multiplication. Since multiplication is a repeated addition, errors here tend to be much larger and more complex to model.
* **Library Verification**: Compares the locally calculated error values against the theoretical values provided by the EvoApprox library metadata.

### 4. matrix_mult.ipynb

* **System-Level Benchmark**: Moves from single operations to a full algorithm (Matrix Multiplication) running on an FPGA (likely using PYNQ).
* **Power Profiling**: Includes code to plot real-time Power (W) consumption, showing how much energy is saved when switching from an exact multiplier to an approximate one.

### 5. OverallMetrics.ipynb

* **Comparative Visualization**: Uses Seaborn boxplots to compare various error metrics (MSE, MAE, MRED) across all tested designs.
* **Pareto Optimization**: Implements the `pareto_frontier` function to identify designs that provide the "best" balance—meaning you can't get more accuracy without using more power.

### 6. Sobel_pl.ipynb

* **Image Processing Pipeline**: Applies the approximate hardware to a Sobel edge detection filter.
* **Visual Validation**: Displays the resulting "edge image" to see if the human eye can actually detect the errors introduced by the approximate arithmetic.

### 7. matmul.cpp

* **HLS Optimization**: High-Level Synthesis code for matrix multiplication.
* **Array Partitioning**: Uses `#pragma HLS ARRAY_PARTITION` to break data into multiple memory banks, allowing the FPGA to read all inputs simultaneously for higher throughput.
* **Hardware Buffering**: Implements local buffers (A, B, and C) to minimize expensive access to the main system memory (DRAM).

### 8. sobel.cpp

* **Sobel Architecture**: C++ source code defining the 3x3 sliding window used for edge detection.
* **Hardware Parallelism**: Uses `#pragma HLS UNROLL` to process multiple pixels or multiplication steps at once, significantly speeding up image processing compared to a CPU.

### 9. Error_Raw_Adders_LOA.csv

* **LOA Dataset**: A raw table recording the exact MSE, MAE, and EP (Error Probability) for every LOA bit-width configuration. This is the source data for the charts in your paper.

### 10. Error_Raw_Adders.csv

* **Generic Adder Dataset**: Data for various 16-bit approximate adders (add16se series). It includes columns for both your calculated results and the original library specifications.

### 11. Error_Raw_Mult.csv

* **Multiplier Dataset**: Records the massive Error Distance and Worst-Case Error values for multipliers, providing the data needed to show why multipliers are more sensitive to approximation than adders.

### 12. results-dse - MSE.csv

* **Design Space Exploration (DSE) - Error**: Records how Mean Square Error changes across 88 different hardware "inputs" or configurations.

### 13. results-dse - overall.csv

* **Hardware Resources**: A master table linking accuracy (MSE/MAE) with physical chip usage (LUTs and Flip-Flops). This is the key to proving that your "model-free" or "DFG" approach actually saves space.

### 14. results-dse - plot.csv

* **Visualization Source**: A curated table used specifically for generating the "Accuracy vs. Power" scatter plots often found in MICRO journal papers.

### 15. results-dse - PSNR.csv

* **Visual Quality Data**: Records Peak Signal-to-Noise Ratio (PSNR) values. It shows how "noisy" the Sobel filter output becomes when using different approximate hardware.

### 16. results-dse - SSIM.csv

* **Structural Fidelity**: Records the Structural Similarity Index (SSIM). It measures how well the outlines and shapes in your image are preserved despite the mathematical errors.

### 17. requirements.txt

* **Environment Reproducibility**: Lists every Python library version (e.g., `scikit-image==0.21.0`, `scipy==1.10.1`) used in your research to ensure other scientists can reproduce your results.
