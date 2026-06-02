#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
    vector<double> x = {1, 2, 3, 4, 5, 6, 7, 8, 9}; 
    vector<double> y = {2, 4, 6, 8, 10, 12, 14, 16, 18};
    
    int n = x.size();
    double sumX = 0, sumY = 0, sumXY = 0, sumX2 = 0;

    for (int i = 0; i < n; i++) {
        sumX += x[i];
        sumY += y[i];
        sumXY += x[i] * y[i];
        sumX2 += x[i] * x[i];
    }
    
    double b1 = (n * sumXY - sumX * sumY) / (n * sumX2 - sumX * sumX);
    double b0 = (sumY - b1 * sumX) / n;

    cout << "MODELO DE REGRESION LINEAL SIMPLE (SLR)\n";
    cout << "Ecuacion de Regresion: y = " << b0 << " + " << b1 << "x\n";
    cout << "Donde: y = Sales, x = Advertising\n\n";

    vector<double> predicciones_x = {10, 15, 20, 25, 30};
    
    cout << "PREDICCIONES DE VENTAS:\n";
    cout << "Advertising (x) | Sales Predicho (y)\n";
    
    for (double val_x : predicciones_x) {
        double val_y = b0 + b1 * val_x;
        cout << fixed << setprecision(2) << "      " << val_x << "             " << val_y << "\n";
    }

    
    cout << "\n\nCalculo de Medidas de Tendencia Central (Datos agrupados)\n";

    vector<double> lim_inf = {10, 20, 30, 40, 50};
    vector<double> lim_sup = {20, 30, 40, 50, 60};
    vector<double> frec = {5, 10, 15, 8, 2}; 

    int num_clases = lim_inf.size();
    double total_datos = 0; 
    for (int i=0; i<num_clases; i++) {
        total_datos += frec[i];
    }

    double suma_fx = 0;
    vector<double> marca_clase(num_clases);
    for (int i = 0; i < num_clases; i++) {
        marca_clase[i] = (lim_inf[i] + lim_sup[i]) / 2.0; 
        suma_fx += marca_clase[i] * frec[i];              
    }
    double media = suma_fx / total_datos;

    double N2 = total_datos / 2.0;
    double frec_acumulada = 0;
    double frec_ant = 0; 
    int pos_mediana = -1;

    for (int i = 0; i < num_clases; i++) {
        frec_acumulada += frec[i];
        if (frec_acumulada >= N2 && pos_mediana == -1) {
            pos_mediana = i;
            break;
        }
        frec_ant = frec_acumulada; 
    }

    double limite_inf_med = lim_inf[pos_mediana];
    double f_med = frec[pos_mediana];
    double amplitud = lim_sup[pos_mediana] - lim_inf[pos_mediana];
    
    double mediana = limite_inf_med + ((N2 - frec_ant) / f_med) * amplitud;

    int pos_moda = 0;
    double frec_max = frec[0];
    
    for (int i = 1; i < num_clases; i++) {
        if (frec[i] > frec_max) {
            frec_max = frec[i];
            pos_moda = i;
        }
    }

    double limite_inf_moda = lim_inf[pos_moda];
    double f_moda = frec[pos_moda];
    
    double f_ant = (pos_moda > 0) ? frec[pos_moda - 1] : 0; 
    double f_sig = (pos_moda < num_clases - 1) ? frec[pos_moda + 1] : 0;
    double amplitud_moda = lim_sup[pos_moda] - lim_inf[pos_moda];

    double d1 = f_moda - f_ant;
    double d2 = f_moda - f_sig;
    double moda = limite_inf_moda + (d1 / (d1 + d2)) * amplitud_moda;

    cout << "1. Media (Promedio) : " << media << endl;
    cout << "2. Moda             : " << moda << endl;
    cout << "3. Mediana          : " << mediana << endl;

    return 0;
}