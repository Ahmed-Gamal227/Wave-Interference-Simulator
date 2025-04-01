#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>

const double PI = 3.14159265358979323846;
const double WAVELENGTH = 500e-9;    // 500 nm
const double SLIT_WIDTH = 0.1e-3;     // 0.1 mm
const double SLIT_SEPARATION = 0.5e-3; // 0.5 mm ( double-slit)
const double SCREEN_DISTANCE = 1.0;   // 1 meter

void calculatePatterns(std::vector<double>& angles,
    std::vector<double>& single_intensity,
    std::vector<double>& double_intensity) {
    int numPoints = 1000;
    angles.resize(numPoints);
    single_intensity.resize(numPoints);
    double_intensity.resize(numPoints);

    double theta_range = 3 * WAVELENGTH / SLIT_WIDTH;

    for (int i = 0; i < numPoints; ++i) {
        angles[i] = -theta_range + 2 * theta_range * i / (numPoints - 1);
        double theta = angles[i];

        // Single-slit calculation
        double alpha = (PI * SLIT_WIDTH / WAVELENGTH) * sin(theta);
        single_intensity[i] = (alpha == 0) ? 1.0 : pow(sin(alpha) / alpha, 2);

        // Double-slit calculation
        double beta = (PI * SLIT_SEPARATION / WAVELENGTH) * sin(theta);
        double_intensity[i] = single_intensity[i] * pow(cos(beta), 2);
    }
}

void saveData(const std::vector<double>& angles,
    const std::vector<double>& single_intensity,
    const std::vector<double>& double_intensity) {
    std::ofstream outFile("slit_data.txt");
    outFile << "angle_radians single_slit_intensity double_slit_intensity\n";
    for (size_t i = 0; i < angles.size(); ++i) {
        outFile << angles[i] << " " << single_intensity[i] << " " << double_intensity[i] << "\n";
    }
    outFile.close();
}

int main() {
    std::vector<double> angles, single_intensity, double_intensity;

    calculatePatterns(angles, single_intensity, double_intensity);
    saveData(angles, single_intensity, double_intensity);

    std::cout << "Simulation complete. Data saved to 'slit_data.txt'\n";
    return 0;
}