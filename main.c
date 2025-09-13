#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int from_field_to_index(int letter, int number)
{
    return letter-'a'+8*(number-'1');
}

char from_index_to_ASCII(int index)
{
    return index%8+'a';
}

int from_index_to_number(int index)
{
    return index/8+1;
}

int explore(int field, int *chess_board, int move_number, int *chess_board_parents)
{
    int new_fields_visited = 0;
    int rank = field / 8;
    int file = field % 8;
    
    /*static const*/ int knight_displacements[8][2] = {{-2,-1}, {-1,-2}, {1,-2}, {2,-1}, {2,1}, {1,2}, {-1,2}, {-2,1}};
    for (int move_idx = 0; move_idx < sizeof(knight_displacements)/sizeof(knight_displacements[0]); ++move_idx)
    {
        int destination_rank = rank + knight_displacements[move_idx][0];
        int destination_file = file + knight_displacements[move_idx][1];
        
        if (destination_rank >= 0 && destination_rank <= 7 && destination_file >=0 && destination_file <= 7)
        {
            int destination_field = destination_rank*8 + destination_file;
            if (chess_board[destination_field] == 0)
            {
                chess_board[destination_field] = move_number;
                chess_board_parents[destination_field] = field;
                ++new_fields_visited;
            }
        }
    }
    return new_fields_visited;
}

int main()
{
    int letter, number;
    int xb; // начальное положение коня
    int xf; // положение финиша
    int n; // количество слонов
    int el; // положение слона
    
    int cb[64]={0}; // для клеток (chessboard)
    
    // интерпретация ввода
    letter = getchar();
    number = getchar();
    xb = from_field_to_index(letter, number);
    getchar();
    letter = getchar();
    number = getchar();
    xf = from_field_to_index(letter, number);
    getchar();
    n = getchar()-'0';
    // отметка клеток со слонами
    for(int i=0; i<n; ++i){
        getchar();
        letter = getchar();
        number = getchar();
        el = from_field_to_index(letter, number);
        cb[el]=-1;
        for(int j=1; j<8; ++j){
            if(el%8-j>=0){
                if(el-8*j>=0){
                    cb[el-8*j-j]=-1;
                }
                if(el+8*j<=63){
                    cb[el+8*j-j]=-1;
                }
            }
            if(el%8+j<=7){
                if(el-8*j>=0){
                    cb[el-8*j+j]=-1;
                }
                if(el+8*j<=63){
                    cb[el+8*j+j]=-1;
                }
            }
        }
    }
    
    if(cb[xb]==-1){
        printf("Маршрута не существует: начальное поле находится под атакой слона");
        return 0;
    }
    
    int cbp[64]={-1}; // для записи индексов родительских клеток (chessboard pointers, но элементы не указатели)
    
    if(!explore(xb, cb, 1, cbp)){
        printf("Маршрута не существует");
        return 0;
    }
    
    int counter=1;
    int id_of_move=1;
    while(counter && !cb[xf]){
        counter=0;
        for(int i=0; i<64; ++i){
            if(cb[i]==id_of_move){
                counter+=explore(i, cb, id_of_move+1, cbp);
            }
        }
        ++id_of_move;
    }
    
    if(cb[xf]==0){
        printf("Маршрута не существует");
        return 0;
    }
    
    int *final_way;
    final_way = malloc((cb[xf]+1)*sizeof(*final_way));
    if (!final_way) {printf("Ошибка"); exit(1);}
    
    final_way[0]=xb;
    final_way[cb[xf]]=xf;
    for(int i=cb[xf]-1; i>0; --i){
        final_way[i]=cbp[final_way[i+1]];
    }
    
    for(int i=0; i<=cb[xf]; ++i){
        printf("%c%d ", from_index_to_ASCII(final_way[i]), from_index_to_number(final_way[i]));
    }
    
    free(final_way);
    return 0;
}
