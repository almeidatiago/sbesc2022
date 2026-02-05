# Dictionary of Concepts: FPGA Approximate Computing & Error Analysis

## 1. Error & Accuracy Metrics
Terms used to measure the mathematical difference between "exact" (correct) results and "approximate" results.

| Term | Concept / Definition |
| :--- | :--- |
| **Error Distance (ED)** | The absolute numerical difference between the correct result and the approximate result. |
| **Mean Absolute Error (MAE)** | The average of all Error Distances; it shows the general accuracy of the hardware. |
| **Mean Square Error (MSE)** | The average of the squares of errors; it highlights and penalizes larger errors more severely. |
| **Worst-Case Error (WCE)** | The maximum possible error that a specific approximate circuit can produce. |
| **Error Probability (EP)** | The percentage of time that a calculation will result in an incorrect answer. |
| **Mean Relative Error Distance (MRED)** | The average error relative to the magnitude of the correct value (useful for seeing if an error is "large" compared to the number itself). |
| **Error Bias** | Indicates if the errors are consistently higher (positive) or lower (negative) than the true value. |
| **Hamming Distance (HD)** | In binary, the number of bits that are different between the exact result and the approximate result. |
| **Probability Mass Function (PMF)** | A statistical distribution (often a graph) showing how frequently different error values occur. |

## 2. Image Quality Metrics
Concepts used when the approximate hardware is applied to image processing (like the Sobel filter).

| Term | Concept / Definition |
| :--- | :--- |
| **PSNR (Peak Signal-to-Noise Ratio)** | A ratio measuring the quality of a processed image. Higher values mean the image is closer to the original. |
| **SSIM (Structural Similarity Index)** | A metric (0 to 1) that measures how similar the "structure" and textures of two images are. 1.0 means they are identical. |
| **Sobel Filter** | An algorithm used in image processing to detect edges by calculating the intensity gradients of pixels. |

## 3. Hardware & FPGA Design
Terms related to the physical resources and optimization of the chip.

| Term | Concept / Definition |
| :--- | :--- |
| **FPGA (Field Programmable Gate Array)** | A hardware chip that can be reconfigured or "programmed" to perform specific digital logic tasks. |
| **HLS (High-Level Synthesis)** | A tool that converts high-level code (like C++) into hardware description for a chip. |
| **LUT (Lookup Table)** | The basic building block of an FPGA that performs logic functions. Reducing LUTs saves space and power. |
| **FF (Flip-Flop)** | A tiny memory element on the chip used to store a single bit of data. |
| **Power (W)** | The electrical energy consumed by the hardware during operation. |
| **DSE (Design Space Exploration)** | The process of testing many hardware versions to find the best balance of speed, power, and accuracy. |
| **Pareto Frontier** | A set of "optimal" designs where you cannot improve one metric (like power) without making another (like accuracy) worse. |
| **PAP (Power-Area-Product)** | A combined metric used to judge the overall efficiency of a design. |

## 4. Approximate Arithmetic Units
Specific types of simplified hardware used in your project.

| Term | Concept / Definition |
| :--- | :--- |
| **Approximate Computing** | A design approach that intentionally allows for small errors to save battery life, speed, or chip space. |
| **LOA (Lower-Part-OR Adder)** | An adder that simplifies addition by using "OR" logic for the less significant bits. |
| **AMA / AXA** | Families of approximate adders (Approximate Mirror Adder / Approximate XOR Adder) with varying levels of complexity. |
| **add16se / mul16s** | Standard naming for 16-bit approximate adders and multipliers from libraries like *evoapproxlib*. |

## 5. Development Environment
| Term | Concept / Definition |
| :--- | :--- |
| **Jupyter Notebook (.ipynb)** | An interactive file combining live code (Python), equations, and visualizations. |
| **Requirements.txt** | A configuration file listing the Python libraries (NumPy, Scipy, Pandas) needed to run your analysis. |
