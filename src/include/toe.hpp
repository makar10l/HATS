//!SIZE OF TOE!
const int X_SIZE =13;
const int Y_SIZE =7;


class toes{
        public:
                //toe init?
                char toe_e[Y_SIZE][X_SIZE] = {
                {'-','-','-','-','-','-','-','-','-','-','-','-','-'},
                {'|','0','.','.','.','.','.','.','.','.','.','.','|'},
                {'|','.','.','.','.','.','.','.','.','.','.','.','|'},
                {'|','.','.','.','.','.','.','.','.','.','.','.','|'},
                {'|','.','.','.','.','.','.','.','.','.','.','.','|'},
                {'|','.','.','.','.','.','.','.','.','.','.','*','|'},
                {'-','-','-','-','-','-','-','-','-','-','-','-','-'}};
        //clear toe
         void reset(int x, int y, int aix, int aiy){
                for(int y = 1; y < Y_SIZE-1; y++){
                        for(int x = 1; x < X_SIZE-1; x++){
                                toe_e[y][x] = '.';
                        }
                }
                toe_e[y][x] = '0';
                toe_e[aiy][aix] = '*';
        }
        //draw toe
        void out(){
                clear();
                for(int y = 0; y < Y_SIZE; y++){
                for(int x = 0; x < X_SIZE; x++){
                        std::cout << toe_e[y][x];
                }
                std::cout << "\n";
                }
        }
};