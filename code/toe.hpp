#define X_SIZE 13
#define Y_SIZE 7

class toes{
        public:
                char toe_e[Y_SIZE][X_SIZE] = {
                {'-','-','-','-','-','-','-','-','-','-','-','-','-'},
                {'|','.','.','.','.','.','.','.','.','.','.','.','|'},
                {'|','.','.','.','.','.','.','.','.','.','.','.','|'},
                {'|','.','.','.','.','.','.','.','.','.','.','.','|'},
                {'|','.','.','.','.','.','.','.','.','.','.','.','|'},
                {'|','.','.','.','.','.','.','.','.','.','.','.','|'},
                {'-','-','-','-','-','-','-','-','-','-','-','-','-'}};
        void out(int x, int y, int xAI, int yAI){
                system("clear");
                system("cls");
                toe_e[y][x] = '0';
                toe_e[yAI][xAI] = '&';
                for(int y = 0; y < Y_SIZE; y++){
                for(int x = 0; x < X_SIZE; x++){
                        std::cout << toe_e[y][x];
                }
                std::cout << "\n";
                }
        }
        void out(int x, int y){
                system("clear");
                system("cls");
                toe_e[y][x] = '0';
                for(int y = 0; y < Y_SIZE; y++){
                for(int x = 0; x < X_SIZE; x++){
                        std::cout << toe_e[y][x];
                }
                std::cout << "\n";
                }
        }
        void out(){
                system("clear");
                system("cls");
                for(int y = 0; y < Y_SIZE; y++){
                for(int x = 0; x < X_SIZE; x++){
                        std::cout << toe_e[y][x];
                }
                std::cout << "\n";
                }
        }
        void reset(){
                for(int y = 1; y < Y_SIZE-1; y++){
                        for(int x = 1; x < X_SIZE-1; x++){
                                toe_e[y][x] = '.';
                        }
                }
        }
};