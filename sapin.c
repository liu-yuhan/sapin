#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
void print_line_stars(int argu){
  while(argu>0){
    write(1,"*",1);
    argu--;
  }
    write(1,"\n",1);
}

void print_line_space(int argu){
  while(argu>0){
    write(1," ",1);
    argu--;
  }
}

int num_star_first_line_uniblock(int block){
  if(block==1){
     return 1;
  }
return (num_star_first_line_uniblock(block-1)+(((block-1)/2)*2)+4);
}

int num_star_last_line_uniblock(int block){
   int first_line_star = num_star_first_line_uniblock(block);
  return (first_line_star+((block+2)*2));
}

void print_all_stars(int block){
  int temp_block=1;
  int space_this_block;
  int first_line_star_this_block;
  int last_line_star_this_blocks;
  int last_line_star_tree=num_star_last_line_uniblock(block);
  while (temp_block<=block){
    first_line_star_this_block=num_star_first_line_uniblock(temp_block);
    last_line_star_this_blocks=num_star_last_line_uniblock(temp_block);
    space_this_block=(last_line_star_tree-first_line_star_this_block)/2;
    while (first_line_star_this_block<=last_line_star_this_blocks) {
            print_line_space(space_this_block);
            print_line_stars(first_line_star_this_block);
            space_this_block--;
            first_line_star_this_block=first_line_star_this_block+2;
    }
    temp_block++;
  }
}

void print_trunk(int block){
  int counter=0;
while(counter<block){
  int sticks=1+((block/2)*2);
  int space_trunk= (num_star_last_line_uniblock(block)-sticks)/2;
  print_line_space(space_trunk);
  while(sticks>0){
    write(1,"|",1);
    sticks--;
  }
  write(1,"\n",1);
  counter++;
}
}
void sapin(int block ){
  if (block == 0) {
    write(1,"\n",1);
  }
  else{
    print_all_stars(block);
    print_trunk(block);
  }
}

int main(int argc, char *argv[] ) {
int block=atoi(argv[1]);
  sapin(block);
  return 0;
}
