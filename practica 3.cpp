#include <iostream>
#include <iomanip>
#include <string>

int main() {
    
      // Dataset de la matriz de contingencia proporcionada:
   

    double matriz[2][2] = {
        {7.0, 3.0}, // Llueve [B][A], Llueve [B][A']
        {2.0, 6.0}  // No Llueve [B'][A], No Llueve [B'][A']
    };

    double total_A = 9.0;
    double total_A_prime = 9.0;
    double total_B = 10.0;
    double total_B_prime = 8.0;
    double gran_total = 18.0;

    std::cout << "     HANDS-ON 6: PROBABILIDAD MARGINAL, CONJUNTA Y CONDICIONAL\n";

    std::cout << std::fixed << std::setprecision(4);

    // 1. Probabilidades Marginales
    std::cout << "1. PROBABILIDADES MARGINALES:\n";
    std::cout << "   - P(A)  [Nublado]    = " << total_A << " / " << gran_total << " = " << (total_A / gran_total) << "\n";
    std::cout << "   - P(A') [No Nublado] = " << total_A_prime << " / " << gran_total << " = " << (total_A_prime / gran_total) << "\n";
    std::cout << "   - P(B)  [Llueve]     = " << total_B << " / " << gran_total << " = " << (total_B / gran_total) << "\n";
    std::cout << "   - P(B') [No Llueve]  = " << total_B_prime << " / " << gran_total << " = " << (total_B_prime / gran_total) << "\n\n";

    // 2. Probabilidades Conjuntas
    std::cout << "2. PROBABILIDADES CONJUNTAS:\n";
    std::cout << "   - P(A n B)   [Nublado y Llueve]    = " << matriz[0][0] << " / " << gran_total << " = " << (matriz[0][0] / gran_total) << "\n";
    std::cout << "   - P(A' n B)  [No Nublado y Llueve] = " << matriz[0][1] << " / " << gran_total << " = " << (matriz[0][1] / gran_total) << "\n";
    std::cout << "   - P(A n B')  [Nublado y No Llueve] = " << matriz[1][0] << " / " << gran_total << " = " << (matriz[1][0] / gran_total) << "\n";
    std::cout << "   - P(A' n B') [No Nublado y No Ll]= " << matriz[1][1] << " / " << gran_total << " = " << (matriz[1][1] / gran_total) << "\n\n";

    // 3. Probabilidades Condicionales
    std::cout << "3. PROBABILIDADES CONDICIONALES:\n";
    // P(B|A) = P(A n B) / P(A)
    std::cout << "   - P(B|A)   [Dado que esta Nublado, que Llueva]      = " << matriz[0][0] << " / " << total_A << " = " << (matriz[0][0] / total_A) << "\n";
    // P(B|A') = P(A' n B) / P(A')
    std::cout << "   - P(B|A')  [Dado que No esta Nublado, que Llueva]   = " << matriz[0][1] << " / " << total_A_prime << " = " << (matriz[0][1] / total_A_prime) << "\n";
    // P(A|B) = P(A n B) / P(B)
    std::cout << "   - P(A|B)   [Dado que Llueve, que este Nublado]      = " << matriz[0][0] << " / " << total_B << " = " << (matriz[0][0] / total_B) << "\n";
    // P(A'|B') = P(A' n B') / P(B')
    std::cout << "   - P(A'|B') [Dado que No Llueve, que No este Nublado]= " << matriz[1][1] << " / " << total_B_prime << " = " << (matriz[1][1] / total_B_prime) << "\n";

    return 0;
}