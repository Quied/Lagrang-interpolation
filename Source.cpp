#include <iostream>
#include <vector>

class Lagranj {
public:

    std::vector<int>Realese_X;
    std::vector<int>Realese_Y;

    std::vector<int>X;
    std::vector<int>Y;
    std::vector<int>copy;

    int iterat = 0;
    int  max = 0;

    void Fiiling() {
        int a, b; std::cout << "Colums(Y/X): "; std::cin >> a;
        for (int i = 0; i < a; i++) {
            std::cout << "X: "; std::cin >> b; X.push_back(b);

        }
        for (int i = 0; i < a; i++) {
            std::cout << "Y: "; std::cin >> b; Y.push_back(b);
        }
        copy = X;


        for (auto el : X) {
            if (el > max) { max = el; }

        } // Max

    }

    void show() {
        std::cout << std::endl;
        system("cls");
        std::cout << "X |";
        for (auto el : X) {
            std::cout << el << " | ";
        }
        std::cout << std::endl;
        for (int i = 0; i < (X.size() * 2) + 1; i++) {
            std::cout << "- ";
        }
        std::cout << std::endl;
        std::cout << "Y |";
        for (auto el : Y) {
            std::cout << el << " | ";
        }
    }

    void result() {
        std::cout << std::endl << std::endl;
        std::cout << "L = ";
        int step_y = 0;

        for (int i = 0; i < X.size(); i++) {
            iterat = X[i];
            X.erase(X.begin() + i);
            std::cout << std::endl << std::endl;
            std::cout << "    ";
            for (int t = 0; t < X.size(); t++) {
                std::cout << "(x - " << X[t] << ")";
            }
            std::cout << std::endl;
            std::cout << Y[step_y] << " * ";

            for (int i = 0; i < X.size() * 7; i++) {
                std::cout << "-";
            }

            std::cout << " + ";
            std::cout << std::endl;
            std::cout << "    ";
            for (int u = 0; u < X.size(); u++) {
                std::cout << "(" << iterat << " - " << X[u] << ")";
            }
            // std::cout << std::endl;
            step_y++;
            X = copy;
        }
        std::cout << std::endl << std::endl;
    }

    void end() {
        int point;
        std::cout << "Your: ";  std::cin >> point;
        std::cout << " - - - - - - - " << std::endl;
        if (point > max) { std::cout << "More than x" << std::endl; }
        else { // Implemented 

            std::vector<double>List;

            int iterass = 0; // iterator for division main
            double resuu;

            double division_up;
            double division_down;
            double main_division;

            std::vector<int>UP;
            std::vector<int>DOWN;

            std::vector<int>Copy_down;


            int x_rel = point;
            Realese_X = X;
            Realese_Y = Y;


            for (int k = 0; k < X.size(); k++) {
                Realese_X = X;
                Realese_X.erase(Realese_X.begin() + k);
                std::cout << "REL : " << Realese_X.size() << std::endl;

                // Up
                for (int i = 0; i < Realese_X.size(); i++) {
                    UP.push_back(point - Realese_X[i]);
                }

                // Down
                for (int i = 0; i < Realese_X.size(); i++) {
                    DOWN.push_back(X[k] - Realese_X[i]);
                }

                // Division UP
                division_up = UP[0];
                UP.erase(UP.begin());
                for (int i = 0; i < UP.size(); i++) {
                    division_up = division_up * UP[i];
                }
                std::cout << " DIV UP: " << division_up << std::endl;


                // Division down

                division_down = DOWN[0];
                DOWN.erase(DOWN.begin());
                for (int i = 0; i < DOWN.size(); i++) {
                    division_down = division_down * DOWN[i];
                }
                std::cout << "DIV DOWN: " << division_down << std::endl;
                std::cout << "Y: " << Y[iterass] << std::endl;

                main_division = (division_up / division_down) * Y[iterass];
                List.push_back(main_division);
                iterass++;
                std::cout << "Main: " << main_division << std::endl;
                std::cout << "---------- " << std::endl;


            }

            std::cout << "List: " << std::endl;
            for (auto el : List) {
                std::cout << el << " ";
            }

            resuu = List[0];
            List.erase(List.begin());

            for (int i = 0; i < List.size(); i++) {
                resuu = resuu + List[i];
            }

            std::cout << std::endl;
            std::cout << "Answer: " << resuu;

        }

    }
};

int main() {
    srand(time(NULL));


    Lagranj Land;
    Land.Fiiling();
    Land.show();
    Land.result();
    Land.end();


}
