//
// AED, August 2022 (Tomás Oliveira e Silva)
//
// First practical assignement (speed run)
//
// Compile using either
//   cc -Wall -O2 -D_use_zlib_=0 solution_speed_run.c -lm
// or
//   cc -Wall -O2 -D_use_zlib_=1 solution_speed_run.c -lm -lz
//
// Place your student numbers and names here
//   N.Mec. 108615  Name: Tiago Fonseca Cruz
//


//
// static configuration
//

#define _max_road_size_  800  // the maximum problem size
#define _min_road_speed_   2  // must not be smaller than 1, shouldnot be smaller than 2
#define _max_road_speed_   9  // must not be larger than 9 (only because of the PDF figure)


//
// include files --- as this is a small project, we include the PDF generation code directly from make_custom_pdf.c
//

#include <math.h>
#include <stdio.h>
#include "../P02/elapsed_time.h"
#include "make_custom_pdf.c"


//
// road stuff
//

static int max_road_speed[1 + _max_road_size_]; // positions 0.._max_road_size_

static void init_road_speeds(void)
{
  double speed;
  int i;

  for(i = 0;i <= _max_road_size_;i++)
  {
    speed = (double)_max_road_speed_ * (0.55 + 0.30 * sin(0.11 * (double)i) + 0.10 * sin(0.17 * (double)i + 1.0) + 0.15 * sin(0.19 * (double)i));
    max_road_speed[i] = (int)floor(0.5 + speed) + (int)((unsigned int)random() % 3u) - 1;
    if(max_road_speed[i] < _min_road_speed_)
      max_road_speed[i] = _min_road_speed_;
    if(max_road_speed[i] > _max_road_speed_)
      max_road_speed[i] = _max_road_speed_;

  }
}


//
// description of a solution
//

typedef struct
{
  int n_moves;                         // the number of moves (the number of positions is one more than the number of moves)
  int positions[1 + _max_road_size_];  // the positions (the first one must be zero)
}
solution_t;


//
// the (very inefficient) recursive solution given to the students
//

static solution_t solution_1,solution_1_best;
static double solution_1_elapsed_time; // time it took to solve the problem
static unsigned long solution_1_count; // effort dispended solving the problem

/*
static void solution_1_recursion(int move_number,int position,int speed,int final_position)
{
  int i,new_speed;

  // record move
  solution_1_count++;
  solution_1.positions[move_number] = position;
  // is it a solution?
  if(position == final_position && speed == 1)
  {
    // is it a better solution?
    if(move_number < solution_1_best.n_moves)
    {
      solution_1_best = solution_1;
      solution_1_best.n_moves = move_number;
    }
    return;
  }
  // no, try all legal speeds
  for(new_speed = speed - 1;new_speed <= speed + 1;new_speed++)
    if(new_speed >= 1 && new_speed <= _max_road_speed_ && position + new_speed <= final_position)
    {
      for(i = 0;i <= new_speed && new_speed <= max_road_speed[position + i];i++)
        ;
      if(i > new_speed)
        solution_1_recursion(move_number + 1,position + new_speed,new_speed,final_position);
    }
}
*/
////////////////////////////////// NOSSA SOLUÇAO
/*
static int sum_speeds(int n){
  int sum=0;
  for (int j=0; j<=n; j++){
    sum=sum+j;
    
  }
  return  sum;
  }


static void solution_1_recursion( int final_position){
  int i;
  int flag;
  int move_number=1;
  int position=1;
  int speed=1;
  for (i =1; i <=final_position + 1; i++){
    int new_speed;
    int j,w,q;
    solution_1_count++;
    solution_1.positions[move_number] = position;    
    flag = 0;
      if (speed == 0){
        speed=1;
      }
      else if ( i == final_position - 1){
          if (speed!=1){
            speed=speed-1;
          }
      }
      else if ( i == final_position - 2){
          if (speed!=1){
            speed=speed-1;
          }
      }
      else if (sum_speeds(speed)>=final_position-position+1-i-speed){
        speed=speed-1;
      }
      else{
        for(new_speed = speed+1;new_speed>=speed-1 && flag==0;new_speed--){\
          if(new_speed >= 1 && new_speed <= max_road_speed && position + new_speed <= final_position ){
            for (j = 0; j <= new_speed && new_speed<=max_road_speed[position+j]; j++){
              ;
            }
            for (w= 0; w <= new_speed && new_speed<=max_road_speed[position+w+new_speed]; w++){
              ;
            }
            for (q = 0; q <= new_speed && new_speed<=max_road_speed[position+q+new_speed+new_speed]; q++){
              ;
            }
            if (j> new_speed && q>=new_speed && w>=new_speed){  
              flag=1;      
              speed=new_speed;
              move_number=move_number+1;
              position=position+new_speed;
            }
          }
        }  
    }
  }
  if(position == final_position  && speed == 1){
    if(move_number < solution_1_best.n_moves){
      solution_1_best = solution_1;
      solution_1_best.n_moves = move_number;
    }
    return; 
  }

}


static void solve_1(int final_position)
{
  if(final_position < 1 || final_position > max_road_size)
  {
    fprintf(stderr,"solve_1: bad final_position\n");
    exit(1);
  }
  solution_1_elapsed_time = cpu_time();
  solution_1_count = 0ul;
  solution_1_best.n_moves = final_position + 100;
  solution_1_recursion(final_position); 
  solution_1_elapsed_time = cpu_time() - solution_1_elapsed_time;
}
*/

static void solution_1_recursion(int move_number,int position,int speed,int final_position)
{
  int i, new_speed;
 

  // record move
  solution_1_count++;
  solution_1.positions[move_number] = position;
  // is it a solution?
  if(position == final_position && speed == 1)
  {
    // is it a better solution?
    if(move_number < solution_1_best.n_moves)
    {
      solution_1_best = solution_1;
      solution_1_best.n_moves = move_number;
    }
    return; 
  }
  // no, try all legal speeds
  //if(solution_1_best.positions[move_number]> solution_1.positions[move_number]) return;
    for(new_speed = speed + 1;new_speed >= speed - 1;new_speed--){// "for" serve para verificar para >,< ou = velocidade
      //int sum=(new_speed*(new_speed+1))/2;
      if(new_speed >= 1 && new_speed <= _max_road_speed_ && position + new_speed <= final_position /*&& position+sum <= final_position*/){ //hipotese: para igual position deve ter sempre menos move_number
        for(i = 0;i <= new_speed && new_speed <= max_road_speed[position + i];i++){ // "for" serve para verificar se cumpre o limite para cada posição seguinte
          ;
        }
        if(i > new_speed){ //o limite de velocidade foi verificado e o salto é legal && a solução ainda pode fazer sentido se nº de passos>casas que faltam?
          solution_1_recursion(move_number + 1,position + new_speed,new_speed,final_position);
        }
      }
    }  
}


/*static void solve_1(int final_position)
{
  if(final_position < 1 || final_position > _max_road_size_)
  {
    fprintf(stderr,"solve_1: bad final_position\n");
    exit(1);
  }
  solution_1_elapsed_time = cpu_time();
  solution_1_count = 0ul;
  solution_1_best.n_moves = final_position + 100;
  solution_1_recursion(0,0,0,final_position); 
  solution_1_elapsed_time = cpu_time() - solution_1_elapsed_time;
}*/

static void solve_1(int final_position)
{
  if(final_position < 1 || final_position > _max_road_size_)
  {
    fprintf(stderr,"solve_1: bad final_position\n");
    exit(1);
  }
  solution_1_elapsed_time = cpu_time();
  solution_1_count = 0ul;
  solution_1_best.n_moves = final_position + 100;
  solution_1_recursion(1,1,1,final_position); //aumenta sempre de velocidade no 1º logo
  solution_1_elapsed_time = cpu_time() - solution_1_elapsed_time;
}
//
// example of the slides
//

static void example(void)
{
  int i,final_position;

  srandom(0xAED2022);
  init_road_speeds();
  final_position = 30;
  solve_1(final_position);
  make_custom_pdf_file("example.pdf",final_position,&max_road_speed[0],solution_1_best.n_moves,&solution_1_best.positions[0],solution_1_elapsed_time,solution_1_count,"Plain recursion");
  printf("mad road speeds:");
  for(i = 0;i <= final_position;i++)
    printf(" %d",max_road_speed[i]);
  printf("\n");
  printf("positions:");
  for(i = 0;i <= solution_1_best.n_moves;i++)
    printf(" %d",solution_1_best.positions[i]);
  printf("\n");
}


//
// main program
//

int main(int argc,char *argv[argc + 1])
{
# define _time_limit_  3600.0
  int n_mec,final_position,print_this_one;
  char file_name[64];

  // generate the example data
  if(argc == 2 && argv[1][0] == '-' && argv[1][1] == 'e' && argv[1][2] == 'x')
  {
    example();
    return 0;
  }
  // initialization
  n_mec = (argc < 2) ? 0xAED2022 : atoi(argv[1]);
  srandom((unsigned int)n_mec);
  init_road_speeds();
  // run all solution methods for all interesting sizes of the problem
  final_position = 1;
  solution_1_elapsed_time = 0.0;
  printf("    + --- ---------------- --------- +\n");
  printf("    |                plain recursion |\n");
  printf("--- + --- ---------------- --------- +\n");
  printf("  n | sol            count  cpu time |\n");
  printf("--- + --- ---------------- --------- +\n");
  while(final_position <= _max_road_size_/* && final_position <= 20*/)
  {
    print_this_one = (final_position == 10 || final_position == 20 || final_position == 50 || final_position == 100 || final_position == 200 || final_position == 400 || final_position == 800) ? 1 : 0;
    printf("%3d |",final_position);
    // first solution method (very bad)
    if(solution_1_elapsed_time < _time_limit_)
    {
      solve_1(final_position);
      if(print_this_one != 0)
      {
        sprintf(file_name,"%03d_1.pdf",final_position);
        make_custom_pdf_file(file_name,final_position,&max_road_speed[0],solution_1_best.n_moves,&solution_1_best.positions[0],solution_1_elapsed_time,solution_1_count,"Plain recursion");
      }
      printf(" %3d %16lu %9.3e |",solution_1_best.n_moves,solution_1_count,solution_1_elapsed_time);
    }
    else
    {
      solution_1_best.n_moves = -1;
      printf("                                |");
    }
    // second solution method (less bad)
    // ...

    // done
    printf("\n");
    fflush(stdout);
    // new final_position
    if(final_position < 50)
      final_position += 1;
    else if(final_position < 100)
      final_position += 5;
    else if(final_position < 200)
      final_position += 10;
    else
      final_position += 20;
  }
  printf("--- + --- ---------------- --------- +\n");
  return 0;
# undef _time_limit_
}
