#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <string>
#include <numeric>
#include <algorithm>
#include <map>

using namespace std;

// Función auxiliar para imprimir líneas divisorias
void printLine(int n, char c = '-') {
    cout << string(n, c) << "\n";
}

// HANDS-ON 1: Regresión Lineal Simple (Caso de Verificación)
void handsOn1() {
    cout << "  HANDS-ON 1: REGRESIÓN LINEAL SIMPLE (VERIFICACIÓN)\n";
    
    vector<double> x = {1, 2, 3, 4, 5};
    vector<double> y = {2, 4, 6, 8, 10};
    int n = x.size();
    
    double sumX = 0, sumY = 0, sumXY = 0, sumXX = 0;
    for(int i = 0; i < n; ++i) {
        sumX += x[i];
        sumY += y[i];
        sumXY += x[i] * y[i];
        sumXX += x[i] * x[i];
    }
    
    double b1 = (n * sumXY - sumX * sumY) / (n * sumXX - sumX * sumX);
    double b0 = (sumY - b1 * sumX) / n;
    
    cout << "Datos: D = {(1,2), (2,4), (3,6), (4,8), (5,10)}\n";
    cout << "Resultados calculados:\n";
    cout << "  B1 (Pendiente)    = " << fixed << setprecision(2) << b1 << "\n";
    cout << "  B0 (Intercepto)   = " << b0 << "\n";
    cout << "Ecuación de Regresión: Y = " << b0 << " + " << b1 << " * X\n";
    cout << "Verificación: Para X=3, Y_pred = " << b0 + b1 * 3 << " (Esperado: 6)\n";
}

// HANDS-ON 2: Regresión Lineal Simple (Caso Benetton)
void handsOn2() {
    cout << "  HANDS-ON 2: REGRESIÓN LINEAL SIMPLE (CASO BENETTON)\n";
    
    // Datos reales de Displayr para el caso Benetton (en millones)
    vector<double> adv = {43.60, 50.44, 59.01, 66.30, 82.36, 92.15, 100.51, 110.06, 111.51};
    vector<double> sales = {1261.08, 1475.28, 1657.52, 2059.05, 2303.76, 2512.64, 2751.46, 2787.67, 2939.13};
    int n = adv.size();
    
    double sumX = 0, sumY = 0, sumXY = 0, sumXX = 0, sumYY = 0;
    for(int i = 0; i < n; ++i) {
        sumX += adv[i];
        sumY += sales[i];
        sumXY += adv[i] * sales[i];
        sumXX += adv[i] * adv[i];
        sumYY += sales[i] * sales[i];
    }
    
    double b1 = (n * sumXY - sumX * sumY) / (n * sumXX - sumX * sumX);
    double b0 = (sumY - b1 * sumX) / n;
    
    double numR = (n * sumXY - sumX * sumY);
    double denR = sqrt((n * sumXX - sumX * sumX) * (n * sumYY - sumY * sumY));
    double r = numR / denR;
    double r2 = r * r;
    
    cout << left << setw(15) << "Publicidad (X)" << "  " << setw(15) << "Ventas (Y)" << "\n";
    printLine(35, '-');
    for(int i = 0; i < n; ++i) {
        cout << left << setw(15) << adv[i] << "  " << setw(15) << sales[i] << "\n";
    }
    printLine(35, '=');
    cout << "Resultados de la Regresión:\n";
    cout << "  B1 (Efecto publicitario) = " << fixed << setprecision(4) << b1 << "\n";
    cout << "  B0 (Ventas base)         = " << b0 << "\n";
    cout << "  Ecuación: Ventas = " << b0 << " + " << b1 << " * Publicidad\n";
    cout << "  Coeficiente de Correlación (r)     = " << r << "\n";
    cout << "  Coeficiente de Determinación (R^2) = " << r2 << " (" << r2*100 << "%)\n";
}

// HANDS-ON 3: Tabla de Frecuencias Simples
void handsOn3() {
    cout << "  HANDS-ON 3: TABLA DE FRECUENCIAS SIMPLES\n";
    
    vector<string> dataset = {"CARRO", "AVION", "TREN", "BARCO", "CARRO", "TREN", "CARRO", "AVION", "CARRO", "BARCO"};
    int n = dataset.size();
    
    map<string, int> counts;
    for(const auto& item : dataset) {
        counts[item]++;
    }
    
    cout << left << setw(12) << "Categoría" << "  " 
         << setw(8) << "Freq (f)" << "  " 
         << setw(10) << "Rel (fr)" << "  " 
         << "Porcentaje (%)" << "\n";
    printLine(50, '-');
    
    for(const auto& pair : counts) {
        double fr = (double)pair.second / n;
        double pct = fr * 100;
        cout << left << setw(12) << pair.first << "  "
             << setw(8) << pair.second << "  "
             << setw(10) << fixed << setprecision(4) << fr << "  "
             << fixed << setprecision(2) << pct << "%\n";
    }
    printLine(50, '=');
    cout << "Total de observaciones (n) = " << n << "\n";
}

// HANDS-ON 4 & 5: Tabla de Frecuencias Extendida y Medidas de Tendencia Central
void handsOn4y5() {
    cout << "  HANDS-ON 4 & 5: TABLA EXTENDIDA Y MEDIDAS GRUPALES\n";
    
    // Dataset de 35 números continuos
    vector<double> data = {
        12.5, 14.2, 15.0, 15.5, 16.1, 16.8, 17.2, 17.8, 18.0, 18.3,
        18.8, 19.1, 19.5, 19.9, 20.2, 20.5, 20.9, 21.3, 21.7, 22.1,
        22.4, 22.8, 23.2, 23.7, 24.1, 24.6, 25.0, 25.5, 26.2, 26.9,
        27.4, 28.1, 28.8, 29.5, 30.5
    };
    int n = data.size();
    
    double minVal = data.front();
    double maxVal = data.back();
    double range = maxVal - minVal;
    
    // Regla de Sturges: k = 1 + 3.322 * log10(n) -> para n=35, k ≈ 6
    int k = 6;
    double amplitude = range / k;
    
    vector<int> freq(k, 0);
    for(double val : data) {
        for(int i = 0; i < k; ++i) {
            double low = minVal + i * amplitude;
            double high = low + amplitude;
            if (i == k - 1) {
                if (val >= low && val <= high + 0.001) {
                    freq[i]++;
                    break;
                }
            } else {
                if (val >= low && val < high) {
                    freq[i]++;
                    break;
                }
            }
        }
    }
    
    cout << "Análisis de Datos Agrupados:\n";
    cout << "  Mínimo = " << minVal << ", Máximo = " << maxVal << "\n";
    cout << "  Rango = " << range << ", Clases (Sturges) = " << k << ", Amplitud = " << amplitude << "\n\n";
    
    cout << left << setw(4) << "Cl" << "  "
         << setw(15) << "Intervalo" << "  "
         << setw(5) << "f" << "  "
         << setw(6) << "Xc" << "  "
         << setw(5) << "Fa" << " "
         << setw(8) << "fr" << "  "
         << setw(8) << "fra" << "  "
         << "Porcentaje" << "\n";
    printLine(75, '-');
    
    int fa = 0;
    double sumFXc = 0;
    
    struct ClassRow {
        double low, high, xc;
        int f, fa;
    };
    vector<ClassRow> rows;
    
    for(int i = 0; i < k; ++i) {
        double low = minVal + i * amplitude;
        double high = low + amplitude;
        double xc = (low + high) / 2.0;
        fa += freq[i];
        double fr = (double)freq[i] / n;
        double fra = (double)fa / n;
        double pct = fr * 100;
        
        sumFXc += freq[i] * xc;
        
        rows.push_back({low, high, xc, freq[i], fa});
        
        string interval = "[" + to_string(low).substr(0,4) + " - " + to_string(high).substr(0,4) + (i == k-1 ? "]" : ")");
        cout << left << setw(4) << (i+1) << "  "
             << setw(15) << interval << "  "
             << setw(5) << freq[i] << "  "
             << setw(6) << fixed << setprecision(2) << xc << " "
             << setw(5) << fa << "  "
             << setw(8) << fixed << setprecision(4) << fr << "  "
             << setw(8) << fra << "  "
             << fixed << setprecision(2) << pct << "%\n";
    }
    printLine(75, '=');
    
    // Medidas de Tendencia Central
    double meanG = sumFXc / n;
    
    double halfN = n / 2.0;
    int medIdx = 0;
    for(int i = 0; i < k; ++i) {
        if (rows[i].fa >= halfN) {
            medIdx = i;
            break;
        }
    }
    double L_med = rows[medIdx].low;
    int Fa_prev = (medIdx > 0) ? rows[medIdx-1].fa : 0;
    double f_med = rows[medIdx].f;
    double medianG = L_med + ((halfN - Fa_prev) / f_med) * amplitude;
    
    int modIdx = 0;
    for(int i = 1; i < k; ++i) {
        if (rows[i].f > rows[modIdx].f) {
            modIdx = i;
        }
    }
    double L_mod = rows[modIdx].low;
    double f_mod = rows[modIdx].f;
    double f_mod_prev = (modIdx > 0) ? rows[modIdx-1].f : 0;
    double f_mod_next = (modIdx < k-1) ? rows[modIdx+1].f : 0;
    double d1 = f_mod - f_mod_prev;
    double d2 = f_mod - f_mod_next;
    double modeG = L_mod + (d1 / (d1 + d2)) * amplitude;
    
    cout << "Medidas de Tendencia Central para Datos Agrupados:\n";
    cout << "  Media Grupal (X_barra) = " << fixed << setprecision(4) << meanG << "\n";
    cout << "  Mediana Grupal (Me)    = " << medianG << "\n";
    cout << "  Moda Grupal (Mo)       = " << modeG << "\n";
}

// HANDS-ON 6: Probabilidades en Matriz de Contingencia
void handsOn6() {
    cout << "  HANDS-ON 6: PROBABILIDADES EN MATRIZ DE CONTINGENCIA\n";
    
    double n_AB = 7;   // Nublado y Llueve
    double n_ABp = 2;  // Nublado y No Llueve
    double n_ApB = 3;  // No Nublado y Llueve
    double n_ApBp = 6; // No Nublado y No Llueve
    
    double total_A = n_AB + n_ABp;    // 9
    double total_Ap = n_ApB + n_ApBp; // 9
    double total_B = n_AB + n_ApB;    // 10
    double total_Bp = n_ABp + n_ApBp; // 8
    double grandTotal = total_A + total_Ap; // 18
    
    cout << "Matriz de Contingencia Registrada:\n";
    cout << "                  Llueve (B)  No Llueve (B')  Total\n";
    printLine(55, '-');
    cout << "  Nublado (A)         7             2           " << (int)total_A << "\n";
    cout << "  No Nublado(A')      3             6           " << (int)total_Ap << "\n";
    printLine(55, '-');
    cout << "  Total              10             8           " << (int)grandTotal << "\n\n";
    
    cout << "1. Probabilidades Marginales:\n";
    cout << "   P(A)  [Nublado]    = " << total_A / grandTotal << "\n";
    cout << "   P(B)  [Llueve]     = " << total_B / grandTotal << "\n\n";
    
    cout << "2. Probabilidades Conjuntas:\n";
    cout << "   P(A ∩ B)   = " << n_AB / grandTotal << "\n\n";
    
    cout << "3. Probabilidades Condicionales Clave:\n";
    cout << "   P(A|B)  [Dado que llueve, que esté nublado] = " << n_AB / total_B << "\n";
    cout << "   P(B|A)  [Dado que está nublado, que llueva] = " << n_AB / total_A << "\n";
}

int main() {
    cout << fixed << setprecision(4);
    
    handsOn1();
    handsOn2();
    handsOn3();
    handsOn4y5();
    handsOn6();
    
    return 0;
}