#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include <windows.h>
#include <conio.h>

struct user
{
    char name [100];
    int point;
};

struct mrjack
{
    char mr_name [100];
    int mr_point;
    char mr_roll[100];
    int mr_hourglass;
};

struct detector
{
    char detector_name [100];
    int detector_point;
    char detector_roll[100];
};

struct rolls
{
    char roll[100];
    char roll2[100];
    int hourglass;
};

struct acc_rolls
{
    char acc_roll[100];
    int acc_hourglass;
};

struct main_tail
{
    char map[3][3];
    char map1[3][3];
    char map2[3][3];
    char map3[3][3];
    char place2[3][3];
    char place4[3][3];
    char place5[3][3];
    char place6[3][3];
    char place7[3][3];
    char place9[3][3];
    struct main_tail *next;
};

struct token
{
    char token_name[100];
};

struct turn_token
{
    int turn;
    int hourglass;
};

struct map2
{
    char space[50];
    char space2[50];
    char rol[20];
    char rol1[20];
    char rol2[20];
};

struct token_moves
{
    char move[3][3];
};

struct user user[20];
struct rolls member[10];
struct acc_rolls acc_rolls[10];
struct token token[8];
struct map2 map2[20];
struct turn_token turn[8];
struct token_moves token_moves[10];
struct main_tail *head=NULL;
struct mrjack  mrjack;
struct detector detector;

int user_number=0;
int game_turn=0;
int n,m,search2,present;
char player1[100],player2[100];
int tail_index=0;
int search1=0;
int sherlock_point=3;
int watson_point=6;
int toby_point=10;
int bot_play=0;

int mainmenu(void);
void makerolls(void);
void make_token_move(void);
struct main_tail*making_tails(void);
void new_game(void);
void player_identify(void);
void lets_play(void);
void last_match(void);
void  main_play(void);
void roll_of_players(char player1[100],char player2[100]);
void game_display(void);
void game(void);
void gude(void);
void random(void);
void detector_func(void);
void mrjack_func(void);
void showing_tokens(void);
void sherlock_move(void);
void watson_move(void);
void toby_move(void);
void suspected_token(void);
void onetokenmove(void);
void turn_90(void);
void turn_180(void);
void token_move(void);
void update_game_display(void);
void Confess(void);
void asking(void);
void setting(void);
void name_edit(void);
void rolls_edit(void);
void load_game(void);
void save_game(void);
void save_map(void);
void save_rolls(void);
void save_users_detail(void);
void list_of_players(void);
int exitf(void);
int saving_ask(void);
void change_color(int textColor,int backColor);
void main_play_bot(void);
void roll_of_player_bot(char player1[100]);
void game_bot(void);
void game_display_bot(void);
void detector_func_bot(void);
void mrjack_func_bot(void);
void showing_tokens_bot(void);
void suspected_token_bot(void);
void Confess_bot(void);
void asking_bot(void);

int main()
{
    mainmenu();
}

int mainmenu(void)
{
    change_color(10,0);
    system("cls");
    printf("welcome to the game\n");
    printf("1)new game\n");
    printf("2)load last game\n");
    printf("3)save game\n");
    printf("4)setting\n");
    printf("5)list of players\n");
    printf("6)exit\n");
    makerolls();
    int choice;
    scanf("%d",&choice);
    if(choice==1)
        new_game();
    if(choice==2)
    load_game();
    if(choice==3)
        save_game();
    if(choice==4)
        setting();
    if(choice==5)
        list_of_players();
    if(choice==6)
        if(exitf()==0)
        return 0;
    else
        mainmenu();

}

void new_game(void)
{
    system("cls");
    printf("1)player identify\n");
    printf("2)lets play !\n");
    printf("3)load last present game\n");
    printf("4)back to menu\n");
    int choice;
    scanf("%d",&choice);
    if(choice==1)
        player_identify();
    if(choice==2)
        lets_play();
    if(choice==3)
        last_match();
    if(choice==4)
        mainmenu();
    else
        new_game();
}

void makerolls(void)
{
    strcpy(member[0].roll,"Insp. Lestrade");
    strcpy(member[0].roll2,"I.L");
    member[0].hourglass=0;
    making_tails();
    strcpy(member[1].roll,"Jeremy Bert");
    strcpy(member[1].roll2,"J.B");
    member[1].hourglass=1;
    making_tails();
    strcpy(member[2].roll,"John Pizer");
    strcpy(member[2].roll2,"J.P");
    member[2].hourglass=1;
    making_tails();
    strcpy(member[3].roll,"John Smith");
    strcpy(member[3].roll2,"J.S");
    member[3].hourglass=1;
    making_tails();
    strcpy(member[4].roll,"Joseph Lane");
    strcpy(member[4].roll2,"J.L");
    member[4].hourglass=1;
    making_tails();
    strcpy(member[5].roll,"Madame");
    strcpy(member[5].roll2,"Mad");
    member[5].hourglass=2;
    making_tails();
    strcpy(member[6].roll,"Miss Stealthy");
    strcpy(member[6].roll2,"M.S");
    member[6].hourglass=1;
    making_tails();
    strcpy(member[7].roll,"Sgt Goodly");
    strcpy(member[7].roll2,"S.G");
    member[7].hourglass=0;
    making_tails();
    strcpy(member[8].roll,"William GULL");
    strcpy(member[8].roll2,"W.G");
    member[8].hourglass=1;
    making_tails();

    strcpy(token[0].token_name,"Holmes");
    strcpy(token[1].token_name,"Watson");
    strcpy(token[2].token_name,"Toby.");
    strcpy(token[3].token_name,"Detector team");
    strcpy(token[4].token_name,"turn 90");
    strcpy(token[5].token_name,"turn 180");
    strcpy(token[6].token_name,"token move");
    strcpy(token[7].token_name,"suspected token");

    strcpy(map2[0].space,"   (     )  ");
    strcpy(map2[1].space,"   (     )  ");
    strcpy(map2[2].space,"   (     )  ");
    strcpy(map2[3].space,"(Holmes)     ");
    strcpy(map2[4].space,"(      )     ");
    strcpy(map2[5].space,"(      )     ");
    strcpy(map2[6].space,"  (Watson)\n");
    strcpy(map2[7].space,"  (      )\n");
    strcpy(map2[8].space,"  (      )\n");
    strcpy(map2[9].space,"    (     ) ");
    strcpy(map2[10].space,"    (Toby.) ");
    strcpy(map2[11].space,"    (     ) ");
    strcpy(map2[0].space2,"   (     )  ");
    strcpy(map2[1].space2,"(      )     ");
    strcpy(map2[2].space2,"  (      )\n");
    strcpy(map2[3].space2,"    (     ) ");
    strcpy(map2[0].rol,"   (Holmes)  ");
    strcpy(map2[1].rol,"(Holmes)     ");
    strcpy(map2[2].rol,"  (Holmes)\n");
    strcpy(map2[3].rol,"    (Holmes) ");
    strcpy(map2[0].rol1,"   (Watson)  ");
    strcpy(map2[1].rol1,"(Watson)     ");
    strcpy(map2[2].rol1,"  (Watson)\n");
    strcpy(map2[3].rol1,"    (Watson) ");
    strcpy(map2[0].rol2,"   (Toby.)  ");
    strcpy(map2[1].rol2,"(Toby.)     ");
    strcpy(map2[2].rol2,"  (Toby.)\n");
    strcpy(map2[3].rol2,"    (Toby.) ");

    for(int i=0; i<8; i-=-1){
        turn[i].turn=i+1;
        turn[i].hourglass=1;
    }
    detector.detector_point=0;
    mrjack.mr_point=0;
    make_token_move();
}

struct main_tail *making_tails(void)
{
    struct main_tail *tail;
    tail=(struct  main_tail*)malloc(sizeof(struct  main_tail));

    tail->map1[0][0]='O';
    tail->map1[0][1]='H';
    tail->map1[0][2]='O';
    tail->map1[1][0]='O';
    tail->map1[1][1]='H';
    tail->map1[1][2]='H';
    tail->map1[2][0]='O';
    tail->map1[2][1]='H';
    tail->map1[2][2]='O';

    tail->map2[0][0]='O';
    tail->map2[0][1]='H';
    tail->map2[0][2]='O';
    tail->map2[1][0]='H';
    tail->map2[1][1]='H';
    tail->map2[1][2]='O';
    tail->map2[2][0]='O';
    tail->map2[2][1]='H';
    tail->map2[2][2]='O';

    tail->map3[0][0]='O';
    tail->map3[0][1]='H';
    tail->map3[0][2]='O';
    tail->map3[1][0]='H';
    tail->map3[1][1]='H';
    tail->map3[1][2]='H';
    tail->map3[2][0]='O';
    tail->map3[2][1]='O';
    tail->map3[2][2]='O';

    tail->place2[0][0]='O';
    tail->place2[0][1]='H';
    tail->place2[0][2]='O';
    tail->place2[1][0]='H';
    tail->place2[1][1]='H';
    tail->place2[1][2]='H';
    tail->place2[2][0]='O';
    tail->place2[2][1]='O';
    tail->place2[2][2]='O';

  for(int i=0;i<3;i-=-1)
        for(int j=0;j<3;j-=-1)
        tail->place4[i][j]=tail->place2[i][j];

  for(int i=0;i<3;i-=-1)
        for(int j=0;j<3;j-=-1)
        tail->place5[i][j]=tail->place2[i][j];

  for(int i=0;i<3;i-=-1)
        for(int j=0;j<3;j-=-1)
        tail->place5[i][j]=tail->place2[i][j];

   for(int i=0;i<3;i-=-1)
        for(int j=0;j<3;j-=-1)
        tail->place6[i][j]=tail->place2[i][j];

   for(int i=0;i<3;i-=-1)
        for(int j=0;j<3;j-=-1)
        tail->place7[i][j]=tail->place2[i][j];

   for(int i=0;i<3;i-=-1)
        for(int j=0;j<3;j-=-1)
        tail->place9[i][j]=tail->place2[i][j];

    head=tail;
    head->next= NULL;
}

void make_token_move(void)
{
    for(int i=0;i<3;i-=-1)
        for(int j=0;j<3;j-=-1)
        token_moves[1].move[i][j]=head->map1[i][j];

    for(int i=0;i<3;i-=-1)
        for(int j=0;j<3;j-=-1)
        token_moves[2].move[i][j]=head->place2[i][j];

    for(int i=0;i<3;i-=-1)
        for(int j=0;j<3;j-=-1)
        token_moves[3].move[i][j]=head->map2[i][j];

    for(int i=0;i<3;i-=-1)
        for(int j=0;j<3;j-=-1)
        token_moves[4].move[i][j]=head->place4[i][j];

    for(int i=0;i<3;i-=-1)
        for(int j=0;j<3;j-=-1)
        token_moves[5].move[i][j]=head->place5[i][j];

    for(int i=0;i<3;i-=-1)
        for(int j=0;j<3;j-=-1)
        token_moves[6].move[i][j]=head->place6[i][j];

    for(int i=0;i<3;i-=-1)
        for(int j=0;j<3;j-=-1)
        token_moves[7].move[i][j]=head->place7[i][j];

    for(int i=0;i<3;i-=-1)
        for(int j=0;j<3;j-=-1)
        token_moves[8].move[i][j]=head->map3[i][j];

    for(int i=0;i<3;i-=-1)
        for(int j=0;j<3;j-=-1)
        token_moves[9].move[i][j]=head->place9[i][j];
}

void change_token(void)
{
    for(int i=0;i<3;i-=-1)
        for(int j=0;j<3;j-=-1)
        head->map1[i][j]=token_moves[1].move[i][j];

    for(int i=0;i<3;i-=-1)
        for(int j=0;j<3;j-=-1)
        head->place2[i][j]=token_moves[2].move[i][j];

    for(int i=0;i<3;i-=-1)
        for(int j=0;j<3;j-=-1)
        head->map2[i][j]=token_moves[3].move[i][j];

    for(int i=0;i<3;i-=-1)
        for(int j=0;j<3;j-=-1)
        head->place4[i][j]=token_moves[4].move[i][j];

    for(int i=0;i<3;i-=-1)
        for(int j=0;j<3;j-=-1)
        head->place5[i][j]=token_moves[5].move[i][j];

    for(int i=0;i<3;i-=-1)
        for(int j=0;j<3;j-=-1)
        head->place6[i][j]=token_moves[6].move[i][j];

    for(int i=0;i<3;i-=-1)
        for(int j=0;j<3;j-=-1)
        head->place7[i][j]=token_moves[7].move[i][j];

    for(int i=0;i<3;i-=-1)
        for(int j=0;j<3;j-=-1)
        head->map3[i][j]=token_moves[8].move[i][j];

    for(int i=0;i<3;i-=-1)
        for(int j=0;j<3;j-=-1)
        head->place9[i][j]=token_moves[9].move[i][j];
}

void player_identify(void)
{
    system("cls");
    printf("please enter your name: ");
    scanf("%s",&user[user_number].name);
    user[user_number].point=0;
    user_number-=-1;
    printf("your name has been save!\n");
    printf("do you want to enter an other name ?\n1.yes\netc.no\n");
    int choice;
    scanf("%d",&choice);
    if(choice==1)
        player_identify();
    else
        new_game();
}

void last_match(void)
{
    system("cls");
    if(present==1)
    {
            game_display();
    }
    else{
        printf("there isnt any present match!\n");
        printf("1)game menu\n");
        printf("etc. main menu");
    int choice;
    scanf("%d",&choice);
    if(choice==1)
        new_game();
        else
            mainmenu();
    }
}

void lets_play(void)
{
    system("cls");
    printf("1)play with your friends\n");
    printf("2)play with a bot\n");
    printf("3)load last present game\n");
    printf("4)exit\n");
    int choice;
    scanf("%d",&choice);
    if(choice==1)
        main_play();
    if(choice==2)
        main_play_bot();
    if(choice==3)
        last_match();
    if(choice==4)
        new_game();
    else
        lets_play();
}

void  main_play(void)
{
    bot_play=0;
    system("cls");
    printf("please enter the name of first player:");
    scanf("%s",&player1);
    int temp=0;
    for(int i=0; i<user_number; i-=-1)
        if(strcmp(user[i].name,player1)==0)
        {
            temp++;
            n=i;
        }
    if(temp==1)
        printf("%s is player1\n",player1);
    else
    {
        while(temp==0)
        {
            printf("invalid name\n");
            printf("please enter the name of first player :");
            char player3[100];
            scanf("%s",&player3);
            for(int i=0; i<user_number; i-=-1)
                if(strcmp(user[i].name,player3)==0)
                {
                    temp++;
                    n=i;
                    strcpy(player1,player3);
                }

        }
        if(temp==1)
            printf("%s is player1\n",player1);
    }
    printf("please enter the name of second player :");
    scanf("%s",&player2);
    int temp2=0;
    for(int i=0; i<user_number; i-=-1)
        if(strcmp(user[i].name,player2)==0)
        {
            temp2++;
            m=i;
        }

    if(temp2==1)
        printf("%s is player1\n",player1);
    else
    {
        while(temp2==0)
        {
            printf("invalid name !\n");
            printf("please enter the name of second player :");
            char player4[100];
            scanf("%s",&player4);
            for(int i=0; i<user_number; i-=-1)
                if(strcmp(user[i].name,player4)==0)
                {
                    temp2++;
                    m=i;
                    strcpy(player2,player4);
                }
        }
        if(temp2==1)
            printf("%s is player2\n",player2);
    }
    roll_of_players(player1,player2);
}

void roll_of_players(char player1[100],char player2[100])
{
    system("cls");
    printf("lets play !!!");
    int chance;
    time_t t = time(NULL);
    srand(t);
    chance=rand()%2+0;
    if(chance==1)
    {
        printf("%s take your roll\n",player1);
        printf("1) Detector\n");
        printf("2) Mr.Jack\n");
        int choice1;
        scanf("%d",&choice1);
        if(choice1== 1)
        {
            strcpy(detector.detector_name,player1);
            strcpy(mrjack.mr_name,player2);
            printf("%s you are Detector\n",player1);
            printf("%s you are Mr.Jack\n",player2);
            printf("%s please close your eyes\n",player1);
            printf("%s be ready to see your roll\n",player2);
            printf("%s press 1 to see your roll\n",player2);
            int tmp;
            scanf("%d",&tmp);
            if(tmp)
            {
            int rl;
            rl=rand()%8+0;
            search2=rl;
            strcpy(mrjack.mr_roll,member[rl].roll);
            mrjack.mr_hourglass=member[rl].hourglass;
            printf("%s you are %s\n",player2,mrjack.mr_roll);
            printf("%s if you are ready press 1",player2);
            int temp;
            scanf("%d",&temp);
            if(temp==1)
                game();
            }
        }
        else
        {
            printf("%s you are Mr.Jack\n",player1);
            printf("%s you are Detector\n",player2);
            strcpy(detector.detector_name,player2);
            strcpy(mrjack.mr_name,player1);
            printf("%s please close your eyes\n",player2);
            printf("%s be ready to see your roll\n",player1);
            printf("%s press 1 to see your roll\n",player1);
            int tmp;
            scanf("%d",&tmp);
            if(tmp)
            {
            int rl2;
            rl2=rand()%8+0;
            search2=rl2;
            strcpy(mrjack.mr_roll,member[rl2].roll);
            mrjack.mr_hourglass=member[rl2].hourglass;
            printf("%s you are %s\n",player1,mrjack.mr_roll);
            printf("%s if you are ready press 1",player1);
            int temp;
            scanf("%d",&temp);
            if(temp==1)
                game();
            }
        }
    }
    else
    {
        printf("%s take your roll\n",player2);
        printf("1) Detector\n");
        printf("2) Mr.Jack\n");
        int choice2;
        scanf("%d",&choice2);
        if(choice2== 1)
        {
            printf("%s you are Detector\n",player2);
            printf("%s you are Mr.Jack\n",player1);
            strcpy(detector.detector_name,player2);
            strcpy(mrjack.mr_name,player1);
            printf("%s please close your eyes\n",player2);
            printf("%s be ready to see your roll\n",player1);
            printf("%s press 1 to see your roll\n",player1);
            int tmp;
            scanf("%d",&tmp);
            if(tmp)
            {
            int rl2;
            rl2=rand()%8+0;
            search2=rl2;
            strcpy(mrjack.mr_roll,member[rl2].roll);
            mrjack.mr_hourglass=member[rl2].hourglass;
            printf("%s you are %s\n",player1,mrjack.mr_roll);
            printf("%s if you are ready press 1",player1);
            int temp;
            scanf("%d",&temp);
            if(temp==1)
                game();
            }
        }

        if(choice2== 2)
        {

            strcpy(detector.detector_name,player1);
            strcpy(mrjack.mr_name,player2);
            printf("%s you are Detector\n",player1);
            printf("%s you are Mr.Jack\n",player2);
            printf("%s please close your eyes\n",player1);
            printf("%s be ready to see your roll\n",player2);
            printf("%s press 1 to see your roll\n",player1);
            int tmp;
            scanf("%d",&tmp);
            if(tmp)
            {
            int rl;
            rl=rand()%8+0;
            search2=rl;
            strcpy(mrjack.mr_roll,member[rl].roll);
            mrjack.mr_hourglass=member[rl].hourglass;
            printf("%s you are %s\n",player2,mrjack.mr_roll);
            printf("%s if you are ready press 1",player2);
            int temp;
            scanf("%d",&temp);
            if(temp==1)
                game();
            }
        }
    }
}

void game(void)
{
    system("cls");
    present-=-1;
    while(tail_index<9)
        random();
    gude();
}

void random(void)
{
    while(tail_index<9)
    {
        time_t t = time(NULL);
        srand(t);
        int index;
        index=rand()%8+0;
        strcpy(acc_rolls[tail_index].acc_roll,member[index].roll);
        acc_rolls[tail_index].acc_hourglass=member[index].hourglass;
        tail_index++;
        if(tail_index>1)
            for(int j=0; j<tail_index; j-=-1)
            {
                if(strcmp(acc_rolls[j].acc_roll,acc_rolls[tail_index].acc_roll)==0)
                    tail_index--;
            }
    }
}

void gude(void)
{
    int i=0;
    system("cls");
    for(int i=0;i<9;i-=-1)
    printf("%d)%s : %s \n",i+1,member[i].roll,member[i].roll2);
    printf("if you are ready press 1");
    int temp;
    scanf("%d",&temp);
    if(temp==1)
        game_display();
}

void game_display(void)
{
    system("cls");
    if((turn[game_turn].turn>8) || (mrjack.mr_hourglass==6))
    {
        mrjack.mr_point=mrjack.mr_point+100;
        printf("%s was mrjack!\n",mrjack.mr_roll);
        printf("mrjack won!\n");
        printf("%s won!\n",mrjack.mr_name);
        for(int i=0; i<user_number; i-=-1)
            if(strcmp(mrjack.mr_name,user[i].name)==0)
                user[i].point = mrjack.mr_point;
        printf("prss 1 to back to menu\n");
        int choice;
        scanf("%d",&choice);
        if(choice==1)
            mainmenu();
    }
    printf("turn : %d\n",turn[game_turn].turn);
    printf("            ");
    for(int i=0;i<3;i-=-1)
     printf("%s",map2[i].space);
    printf("\n\n");
    struct main_tail *curr;
    curr=(struct  main_tail*)malloc(sizeof(struct  main_tail));
    int temp=0;
    int name=0;
    curr=head;
    printf("             ");
    for(int i=0;i<3;i-=-1)
    printf("%c%c%c ",curr->map1[0][i],curr->map1[0][i],curr->map1[0][i]);
    for(int i=0;i<3;i-=-1)
    printf("%c%c%c ", curr->place2[0][i], curr->place2[0][i], curr->place2[0][i]);
    for(int i=0;i<3;i-=-1)
    printf("%c%c%c ",curr->map2[0][i],curr->map2[0][i],curr->map2[0][i]);;
    printf("\n");
    printf("%s",map2[3].space);
    printf("%c%c%c ",curr->map1[1][0],curr->map1[1][0],curr->map1[1][0]);
    printf("%s ",member[name].roll2);
    name-=-1;
    printf("%c%c%c ",curr->map1[1][2],curr->map1[1][2],curr->map1[1][2]);
    printf("%c%c%c ", curr->place2[1][0], curr->place2[1][0], curr->place2[1][0]);
    printf("%s",member[name].roll2);
    name-=-1;
    printf(" %c%c%c ", curr->place2[1][2], curr->place2[1][2], curr->place2[1][2]);
    printf("%c%c%c ",curr->map2[1][0],curr->map2[1][0],curr->map2[1][0]);
    printf("%s ",member[name].roll2);
    name-=-1;
    printf("%c%c%c",curr->map2[1][2],curr->map2[1][2],curr->map2[1][2]);
    printf("%s",map2[6].space);
    printf("             ");
    for(int i=0;i<3;i-=-1)
    printf("%c%c%c ",curr->map1[2][i],curr->map1[2][i],curr->map1[2][i]);
    for(int i=0;i<3;i-=-1)
    printf("%c%c%c ", curr->place2[2][i], curr->place2[2][i], curr->place2[2][i]);
    for(int i=0;i<3;i-=-1)
    printf("%c%c%c ",curr->map2[2][i],curr->map2[2][i],curr->map2[2][i]);
    printf("\n\n");
    printf("             ");
    for(int i=0;i<3;i-=-1)
    printf("%c%c%c ",curr->place4[0][i],curr->place4[0][i],curr->place4[0][i]);
    for(int i=0;i<3;i-=-1)
    printf("%c%c%c ", curr->place5[0][i], curr->place5[0][i], curr->place5[0][i]);
    for(int i=0;i<3;i-=-1)
    printf("%c%c%c ", curr->place6[0][i], curr->place6[0][i], curr->place6[0][i]);
    printf("\n");
    printf("%s",map2[4].space);
    printf("%c%c%c ", curr->place4[1][0], curr->place4[1][0], curr->place4[1][0]);
    printf("%s ",member[name].roll2);
    name-=-1;
    printf("%c%c%c ", curr->place4[1][2], curr->place4[1][2], curr->place4[1][2]);
    printf("%c%c%c ", curr->place5[1][0], curr->place5[1][0], curr->place5[1][0]);
    printf("%s ",member[name].roll2);
    name-=-1;
    printf("%c%c%c ", curr->place5[1][2], curr->place5[1][2], curr->place5[1][2]);
    printf("%c%c%c ", curr->place6[1][0], curr->place6[1][0], curr->place6[1][0]);
    printf("%s ",member[name].roll2);
    name-=-1;
    printf("%c%c%c ", curr->place6[1][2], curr->place6[1][2], curr->place6[1][2]);
    printf("%s",map2[7].space);
    printf("             ");
    for(int i=0;i<3;i-=-1)
    printf("%c%c%c ", curr->place4[2][i], curr->place4[2][i], curr->place4[2][i]);
    for(int i=0;i<3;i-=-1)
    printf("%c%c%c ", curr->place5[2][i], curr->place5[2][i], curr->place5[2][i]);
    for(int i=0;i<3;i-=-1)
    printf("%c%c%c ", curr->place6[2][i], curr->place6[2][i], curr->place6[2][i]);
    printf("\n\n");
    printf("             ");
    for(int i=0;i<3;i-=-1)
    printf("%c%c%c ", curr->place7[0][i], curr->place7[0][i], curr->place7[0][i]);
    for(int i=0;i<3;i-=-1)
    printf("%c%c%c ", curr->map3[0][i], curr->map3[0][i], curr->map3[0][i]);
    for(int i=0;i<3;i-=-1)
    printf("%c%c%c ", curr->place9[0][i], curr->place9[0][i], curr->place9[0][i]);
    printf("\n");
    printf("%s",map2[5].space);
    printf("%c%c%c ", curr->place7[1][0], curr->place7[1][0], curr->place7[1][0]);
    printf("%s ",member[name].roll2);
    name-=-1;
    printf("%c%c%c ", curr->place7[1][2], curr->place7[1][2], curr->place7[1][2]);
    printf("%c%c%c ", curr->map3[1][0], curr->map3[1][0], curr->map3[1][0]);
    printf("%s ",member[name].roll2);
    name-=-1;
    printf("%c%c%c ", curr->map3[1][2], curr->map3[1][2], curr->map3[1][2]);
    printf("%c%c%c ", curr->place9[1][0], curr->place9[1][0], curr->place9[1][0]);
    printf("%s ",member[name].roll2);
    name-=-1;
    printf("%c%c%c ", curr->place9[1][2], curr->place9[1][2], curr->place9[1][2]);
    printf("%s",map2[8].space);
    printf("             ");
    for(int i=0;i<3;i-=-1)
    printf("%c%c%c ", curr->place7[2][i], curr->place7[2][i], curr->place7[2][i]);
     for(int i=0;i<3;i-=-1)
    printf("%c%c%c ", curr->map3[2][i], curr->map3[2][i], curr->map3[2][i]);
    for(int i=0;i<3;i-=-1)
    printf("%c%c%c ", curr->place9[2][i], curr->place9[2][i], curr->place9[2][i]);
    printf("\n\n");
    printf("           ");
    for(int i=0;i<3;i-=-1)
    printf("%s",map2[i].space);
    printf("\n\n");
    printf("1) exit\n");
    printf("etc. continue\n");
    int tmp;
    scanf("%d",&tmp);
    if(tmp==1)
        lets_play();
    else{
    if(turn[game_turn].turn % 2 == 0 )
    {
        mrjack_func();
        Confess();
    }
    else
    {
        detector_func();
        Confess();
    }
    }

}

void detector_func(void)
{
    printf("detector its your turn !\n");
    showing_tokens();
    printf("mrjack its your turn !\n");
    showing_tokens();
    printf("mrjack its your turn !\n");
    showing_tokens();
    printf("detector its your turn !\n");
    showing_tokens();
}

void mrjack_func(void)
{
    printf("mrjack its your turn !\n");
    showing_tokens();
    printf("detector its your turn !\n");
    showing_tokens();
    printf("detector its your turn !\n");
    showing_tokens();
    printf("mrjack its your turn !\n");
    showing_tokens();
}

void showing_tokens(void)
{
    int chance;
    time_t t = time(NULL);
    srand(t);
    chance=rand()%5+0;
    if(chance==0)
    {
        printf("1) %s\n",token[0].token_name);
        printf("2) %s\n",token[1].token_name);
        printf("3) %s\n",token[4].token_name);
        printf("4) %s\n",token[6].token_name);
        printf("etc.I dont have any decision !!!\n");
        int choice;
        scanf("%d",&choice);
        if(choice==1)
            sherlock_move();
        else if(choice==2)
            watson_move();
        else if(choice==3)
            turn_90();
        else if(choice==4)
            token_move();
        else
            printf("you did not have any decision !\n");
    }
    else if(chance==1)
    {
        printf("1) %s\n",token[2].token_name);
        printf("2) %s\n",token[3].token_name);
        printf("3) %s\n",token[5].token_name);
        printf("4) %s\n",token[7].token_name);
        printf("etc.I dont have any decision !!!\n");
        int choice;
        scanf("%d",&choice);
        if(choice==1)
            toby_move();
        else if(choice==2)
            onetokenmove();
        else if(choice==3)
            turn_180();
        else if(choice==4)
            suspected_token ();
        else
            printf("you did not have any decision !\n");
    }
    else if(chance==2)
    {
        printf("1) %s\n",token[0].token_name);
        printf("2) %s\n",token[1].token_name);
        printf("3) %s\n",token[5].token_name);
        printf("4) %s\n",token[6].token_name);
        printf("etc.I dont have any decision !!!\n");
        int choice;
        scanf("%d",&choice);
        if(choice==1)
            sherlock_move();
        else if(choice==2)
            watson_move();
        else if(choice==3)
            turn_180();
        else if(choice==4)
            token_move();
        else
            printf("you did not have any decision !\n");
    }
    else if(chance==3)
    {
        printf("1) %s\n",token[0].token_name);
        printf("2) %s\n",token[2].token_name);
        printf("3) %s\n",token[4].token_name);
        printf("4) %s\n",token[7].token_name);
        printf("etc.I dont have any decision !!!\n");
        int choice;
        scanf("%d",&choice);
        if(choice==1)
            sherlock_move();
        else if(choice==2)
            toby_move();
        else if(choice==3)
            turn_90();
        else if(choice==4)
            suspected_token ();
        else
            printf("you did not have any decision !\n");
    }
    else
    {
        printf("1) %s\n",token[1].token_name);
        printf("2) %s\n",token[3].token_name);
        printf("3) %s\n",token[5].token_name);
        printf("4) %s\n",token[7].token_name);
        printf("etc.I dont have any decision !!!\n");
        int choice;
        scanf("%d",&choice);
        if(choice==1)
            watson_move();
        else if(choice==2)
            onetokenmove();
        else if(choice==3)
            turn_180();
        else if(choice==4)
            suspected_token ();
        else
            printf("you did not have any decision !\n");
    }
}

void sherlock_move(void)
{
    int jump;
    if(bot_play==0)
    {
        printf("please enter the amount of jump !\n");
        printf("1.one\netc.two\n");
        scanf("%d",&jump);
    }
    if(bot_play==1)
    {
        time_t r = time(NULL);
        srand(r);
        jump=rand()%3+1;
    }
    if(jump==1)
    {
        if(sherlock_point == 0)
        {
            strcpy(map2[0].space,map2[0].space2);
            strcpy(map2[1].space,map2[0].rol);
            sherlock_point=1;
        }
        else if(sherlock_point== 1)
        {
            strcpy(map2[1].space,map2[0].space2);
            strcpy(map2[2].space,map2[0].rol);
            sherlock_point=2;
        }
        else if(sherlock_point== 2)
        {
            strcpy(map2[2].space,map2[0].space2);
            strcpy(map2[6].space,map2[2].rol);
            sherlock_point=6;
        }
        else if(sherlock_point== 3)
        {
            strcpy(map2[3].space,map2[1].space2);
            strcpy(map2[0].space,map2[0].rol);
            sherlock_point=0;
        }
        else if(sherlock_point== 4)
        {
            strcpy(map2[4].space,map2[1].space2);
            strcpy(map2[3].space,map2[0].rol);
            sherlock_point=3;
        }
        else if(sherlock_point== 5)
        {
            strcpy(map2[5].space,map2[1].space2);
            strcpy(map2[4].space,map2[0].rol);
            sherlock_point=4;
        }
        else if(sherlock_point==6)
        {
            strcpy(map2[6].space,map2[2].space2);
            strcpy(map2[7].space,map2[2].rol);
            sherlock_point=7;
        }
        else if(sherlock_point==7)
        {
            strcpy(map2[7].space,map2[2].space2);
            strcpy(map2[8].space,map2[2].rol);
            sherlock_point=8;
        }
        else if(sherlock_point==8)
        {
            strcpy(map2[8].space,map2[2].space2);
            strcpy(map2[11].space,map2[3].rol);
            sherlock_point=11;
        }
        else if(sherlock_point== 9)
        {
            strcpy(map2[9].space,map2[3].space2);
            strcpy(map2[5].space,map2[1].rol);
            sherlock_point=5;
        }
        else if(sherlock_point== 10)
        {
            strcpy(map2[10].space,map2[3].space2);
            strcpy(map2[9].space,map2[3].rol);
            sherlock_point=9;
        }
        else if(sherlock_point== 11)
        {
            strcpy(map2[11].space,map2[3].space2);
            strcpy(map2[10].space,map2[3].rol);
            sherlock_point=10;
        }
    }
    else
    {
        if(sherlock_point== 0)
        {
            strcpy(map2[0].space,map2[0].space2);
            strcpy(map2[2].space,map2[0].rol);
            sherlock_point=2;
        }

        else if(sherlock_point== 1)
        {
            strcpy(map2[1].space,map2[0].space2);
            strcpy(map2[6].space,map2[2].rol);
            sherlock_point=6;
        }

        else if(sherlock_point== 2)
        {
            strcpy(map2[2].space,map2[0].space2);
            strcpy(map2[7].space,map2[2].rol);
            sherlock_point=7;
        }
        else if(sherlock_point== 3)
        {
            strcpy(map2[3].space,map2[1].space2);
            strcpy(map2[1].space,map2[0].rol);
            sherlock_point=1;
        }
        else if(sherlock_point== 4)
        {
            strcpy(map2[4].space,map2[1].space2);
            strcpy(map2[0].space,map2[0].rol);
            sherlock_point=0;
        }
        else if(sherlock_point== 5)
        {
            strcpy(map2[5].space,map2[1].space2);
            strcpy(map2[3].space,map2[0].rol);
            sherlock_point=3;
        }
        else if(sherlock_point==6)
        {
            strcpy(map2[6].space,map2[2].space2);
            strcpy(map2[8].space,map2[2].rol);
            sherlock_point=8;
        }
        else if(sherlock_point==7)
        {
            strcpy(map2[7].space,map2[2].space2);
            strcpy(map2[11].space,map2[3].rol);
            sherlock_point = 11;
        }
        else if(sherlock_point==8)
        {
            strcpy(map2[8].space,map2[2].space2);
            strcpy(map2[10].space,map2[3].rol);
            sherlock_point = 10;
        }
        else if(sherlock_point== 9)
        {
            strcpy(map2[9].space,map2[3].space2);
            strcpy(map2[4].space,map2[1].rol);
            sherlock_point=4;
        }
        else if(sherlock_point== 10)
        {
            strcpy(map2[10].space,map2[3].space2);
            strcpy(map2[5].space,map2[1].rol);
            sherlock_point=5;
        }
        else if(sherlock_point== 11)
        {
            strcpy(map2[11].space,map2[3].space2);
            strcpy(map2[9].space,map2[3].rol);
            sherlock_point=9;
        }
    }
    update_game_display();
}

void watson_move(void)
{
    int jump;
    if(bot_play==0)
    {
        printf("please enter the amount of jump !\n");
        printf("1.one\netc.two\n");
        scanf("%d",&jump);
    }
    if(bot_play==1)
    {
        time_t r = time(NULL);
        srand(r);
        jump=rand()%3+1;
    }
    if(jump==1)
    {
        if(watson_point== 0)
        {
            strcpy(map2[0].space,map2[0].space2);
            strcpy(map2[1].space,map2[0].rol1);
            watson_point=1;
        }
        else if(watson_point== 1)
        {
            strcpy(map2[1].space,map2[0].space2);
            strcpy(map2[2].space,map2[0].rol1);
            watson_point=2;
        }
        else if(watson_point== 2)
        {
            strcpy(map2[2].space,map2[0].space2);
            strcpy(map2[6].space,map2[2].rol1);
            watson_point=6;
        }
        else if(watson_point== 3)
        {
            strcpy(map2[3].space,map2[1].space2);
            strcpy(map2[0].space,map2[0].rol1);
            watson_point=0;
        }
       else  if(watson_point== 4)
        {
            strcpy(map2[4].space,map2[1].space2);
            strcpy(map2[3].space,map2[0].rol1);
            watson_point=3;
        }
        else if(watson_point== 5)
        {
            strcpy(map2[5].space,map2[1].space2);
            strcpy(map2[4].space,map2[0].rol1);
            watson_point=4;
        }
        else if(watson_point == 6)
        {
            strcpy(map2[6].space,map2[2].space2);
            strcpy(map2[7].space,map2[2].rol1);
            watson_point=7;
        }
        else if(watson_point==7)
        {
            strcpy(map2[7].space,map2[2].space2);
            strcpy(map2[8].space,map2[2].rol1);
            watson_point=8;
        }
        else if(watson_point==8)
        {
            strcpy(map2[8].space,map2[2].space2);
            strcpy(map2[11].space,map2[3].rol1);
            watson_point=11;
        }
        else if(watson_point== 9)
        {
            strcpy(map2[9].space,map2[3].space2);
            strcpy(map2[5].space,map2[1].rol1);
            watson_point=5;
        }
        else if(watson_point== 10)
        {
            strcpy(map2[10].space,map2[3].space2);
            strcpy(map2[9].space,map2[3].rol1);
            watson_point=9;
        }
        else if(watson_point== 11)
        {
            strcpy(map2[11].space,map2[3].space2);
            strcpy(map2[10].space,map2[3].rol1);
            watson_point=10;
        }
    }
    else
    {
        if(watson_point== 0)
        {
            strcpy(map2[0].space,map2[0].space2);
            strcpy(map2[2].space,map2[0].rol1);
            watson_point=2;
        }

        else if(watson_point== 1)
        {
            strcpy(map2[1].space,map2[0].space2);
            strcpy(map2[6].space,map2[2].rol1);
            watson_point=6;
        }

        else if(watson_point== 2)
        {
            strcpy(map2[2].space,map2[0].space2);
            strcpy(map2[7].space,map2[2].rol1);
            watson_point=7;
        }
        else if(watson_point== 3)
        {
            strcpy(map2[3].space,map2[1].space2);
            strcpy(map2[1].space,map2[0].rol1);
            watson_point=1;
        }
        else if(watson_point== 4)
        {
            strcpy(map2[4].space,map2[1].space2);
            strcpy(map2[0].space,map2[0].rol1);
            watson_point=0;
        }
        else if(watson_point== 5)
        {
            strcpy(map2[5].space,map2[1].space2);
            strcpy(map2[3].space,map2[0].rol1);
            watson_point=3;
        }
        else if(watson_point==6)
        {
            strcpy(map2[6].space,map2[2].space2);
            strcpy(map2[8].space,map2[2].rol1);
            watson_point=8;
        }
        else if(watson_point==7)
        {
            strcpy(map2[7].space,map2[2].space2);
            strcpy(map2[11].space,map2[3].rol1);
            watson_point= 11;
        }
        else if(watson_point==8)
        {
            strcpy(map2[8].space,map2[2].space2);
            strcpy(map2[10].space,map2[3].rol1);
            watson_point = 10;
        }
        else if(watson_point== 9)
        {
            strcpy(map2[9].space,map2[3].space2);
            strcpy(map2[4].space,map2[1].rol1);
            watson_point=4;
        }
        else if(watson_point== 10)
        {
            strcpy(map2[10].space,map2[3].space2);
            strcpy(map2[5].space,map2[1].rol1);
            watson_point=5;
        }
        else if(watson_point== 11)
        {
            strcpy(map2[11].space,map2[3].space2);
            strcpy(map2[9].space,map2[3].rol1);
            watson_point=9;
        }
    }
    update_game_display();
}

void toby_move(void)
{
    int jump;
    if(bot_play==0)
    {
        printf("please enter the amount of jump !\n");
        printf("1.one\netc.two\n");
        scanf("%d",&jump);
    }
    if(bot_play==1)
    {
        time_t r = time(NULL);
        srand(r);
        jump=rand()%3+1;
    }
    if(jump==1)
    {
        if(toby_point== 0)
        {
            strcpy(map2[0].space,map2[0].space2);
            strcpy(map2[1].space,map2[0].rol2);
            toby_point=1;
        }
        else if(toby_point== 1)
        {
            strcpy(map2[1].space,map2[0].space2);
            strcpy(map2[2].space,map2[0].rol2);
            toby_point=2;
        }
        else if(toby_point== 2)
        {
            strcpy(map2[2].space,map2[0].space2);
            strcpy(map2[6].space,map2[2].rol2);
            toby_point=6;
        }
        else if(toby_point== 3)
        {
            strcpy(map2[3].space,map2[1].space2);
            strcpy(map2[0].space,map2[0].rol2);
            toby_point=0;
        }
        else if(toby_point== 4)
        {
            strcpy(map2[4].space,map2[1].space2);
            strcpy(map2[3].space,map2[0].rol2);
            toby_point=3;
        }
        else if(toby_point== 5)
        {
            strcpy(map2[5].space,map2[1].space2);
            strcpy(map2[4].space,map2[0].rol2);
            toby_point=4;
        }
        else if(toby_point==6)
        {
            strcpy(map2[6].space,map2[2].space2);
            strcpy(map2[7].space,map2[2].rol2);
            toby_point=7;
        }
        else if(toby_point==7)
        {
            strcpy(map2[7].space,map2[2].space2);
            strcpy(map2[8].space,map2[2].rol2);
            toby_point=8;
        }
        else if(toby_point==8)
        {
            strcpy(map2[8].space,map2[2].space2);
            strcpy(map2[11].space,map2[3].rol2);
            toby_point=11;
        }
        else if(toby_point== 9)
        {
            strcpy(map2[9].space,map2[3].space2);
            strcpy(map2[5].space,map2[1].rol2);
            toby_point=5;
        }
        else if(toby_point== 10)
        {
            strcpy(map2[10].space,map2[3].space2);
            strcpy(map2[9].space,map2[3].rol2);
            toby_point=9;
        }
        else if(toby_point== 11)
        {
            strcpy(map2[11].space,map2[3].space2);
            strcpy(map2[10].space,map2[3].rol2);
            toby_point=10;
        }
    }
    else
    {
        if(toby_point== 0)
        {
            strcpy(map2[0].space,map2[0].space2);
            strcpy(map2[2].space,map2[0].rol2);
            toby_point=2;
        }

        else if(toby_point== 1)
        {
            strcpy(map2[1].space,map2[0].space2);
            strcpy(map2[3].space,map2[2].rol2);
            toby_point=3;
        }

        else if(toby_point== 2)
        {
            strcpy(map2[2].space,map2[0].space2);
            strcpy(map2[7].space,map2[2].rol2);
            toby_point=7;
        }
        else if(toby_point== 3)
        {
            strcpy(map2[3].space,map2[1].space2);
            strcpy(map2[1].space,map2[0].rol2);
            toby_point=1;
        }
        else if(toby_point== 4)
        {
            strcpy(map2[4].space,map2[1].space2);
            strcpy(map2[0].space,map2[0].rol2);
            toby_point=0;
        }
        else if(toby_point== 5)
        {
            strcpy(map2[5].space,map2[1].space2);
            strcpy(map2[3].space,map2[0].rol2);
            toby_point=3;
        }
        else if(toby_point==6)
        {
            strcpy(map2[6].space,map2[2].space2);
            strcpy(map2[8].space,map2[2].rol2);
            toby_point=8;
        }
        else if(toby_point==7)
        {
            strcpy(map2[7].space,map2[2].space2);
            strcpy(map2[11].space,map2[3].rol2);
            toby_point= 11;
        }
        else if(toby_point==8)
        {
            strcpy(map2[8].space,map2[2].space2);
            strcpy(map2[10].space,map2[3].rol2);
            toby_point = 10;
        }
        else if(toby_point== 9)
        {
            strcpy(map2[9].space,map2[3].space2);
            strcpy(map2[4].space,map2[1].rol2);
            toby_point=4;
        }
        else if(toby_point== 10)
        {
            strcpy(map2[10].space,map2[3].space2);
            strcpy(map2[5].space,map2[1].rol2);
            toby_point=5;
        }
        else if(toby_point== 11)
        {
            strcpy(map2[11].space,map2[3].space2);
            strcpy(map2[9].space,map2[3].rol2);
            toby_point=9;
        }
    }
    update_game_display();
}

void onetokenmove(void)
{
    int choice;
    printf("1) %s\n",token[0].token_name);
    printf("2) %s\n",token[1].token_name);
    printf("3) %s\n",token[2].token_name);
    printf("etc. no movement\n");
    if(bot_play==1)
    {
        time_t r = time(NULL);
        srand(r);
        choice=rand()%5+1;
    }
    if(bot_play==0)
        scanf("%d",&choice);
    if(choice==1)
        sherlock_move();
    if(choice==2)
        watson_move();
    if(choice==3)
        toby_move();
    else
        printf("you had not any move\n");
}

void suspected_token(void)
{
    printf("who you are?\n");
    printf("1) Detector\n");
    printf("2) Mr.Jack\n");
    int choice;
    scanf("%d",&choice);
    if(choice==1)
    {
        if(search1==search2)
        {
            search1-=-1;
            printf("%s is not the mrjack ...\n",member[search1].roll);
            strcpy(member[search1].roll2,"HHH");
            search1-=-1;
            detector.detector_point=detector.detector_point + 5;
        }
        else
        {
            printf("%s is not the mrjack ...\n",member[search1].roll);
            strcpy(member[search1].roll2,"HHH");
            search1-=-1;
            detector.detector_point=detector.detector_point + 5;
        }
    }
    else
    {
        if(search1==search2)
        {
            search1-=-1;
            printf("%s was killed!\n",member[search1].roll);
            printf("%s is not the mrjack ...\n",member[search1].roll);
            strcpy(member[search1].roll2,"HHH");
            mrjack.mr_hourglass=mrjack.mr_hourglass + member[search1].hourglass;
            if((turn[game_turn].turn>8) || (mrjack.mr_hourglass==6))
            {
                mrjack.mr_point=mrjack.mr_point+100;
                printf("%s was mrjack!\n",mrjack.mr_roll);
                printf("mrjack won!\n");
                for(int i=0;i<user_number;i-=-1)
                    if(strcmp(mrjack.mr_name,user[i].name)==0)
                        user[i].point = mrjack.mr_point;
                printf("%s won!\n",mrjack.mr_name);
                printf("prss 1 to back to menu\n");
                int choice;
                scanf("%d",&choice);
                if(choice==1)
                    mainmenu();
            }
            search1-=-1;
        }
        else
        {
            printf("%s was killed!\n",member[search1].roll);
            printf("%s is not the mrjack ...\n",member[search1].roll);
            strcpy(member[search1].roll2,"HHH");
            mrjack.mr_hourglass=mrjack.mr_hourglass + member[search1].hourglass;
            if((turn[game_turn].turn>8) || (mrjack.mr_hourglass==6))
            {
                mrjack.mr_point=mrjack.mr_point+100;
                printf("%s was mrjack!\n",mrjack.mr_roll);
                printf("mrjack won!\n");
                for(int i=0;i<user_number;i-=-1)
                    if(strcmp(mrjack.mr_name,user[i].name)==0)
                        user[i].point = mrjack.mr_point;
                printf("%s won!\n",mrjack.mr_name);
                printf("prss 1 to back to menu\n");
                int choice;
                scanf("%d",&choice);
                if(choice==1)
                    mainmenu();
            }
            search1-=-1;
        }
    }
    update_game_display();
}

void turn_90(void)
{
    int choice;
    int choice1;
    struct main_tail *curr;
    curr=(struct  main_tail*)malloc(sizeof(struct  main_tail));
    curr=head;
    printf("please enter your place");
    if(bot_play==1)
    {
        time_t r = time(NULL);
        srand(r);
        choice=rand()%10+1;
        printf("1)clockwise\n");
        printf("2)counter clockwise\n");
        time_t e = time(NULL);
        srand(e);
        choice1=rand()%3+1;
    }
    if(bot_play==0)
    {
        scanf("%d",&choice);
        printf("1)clockwise\n");
        printf("2)counter clockwise\n");
        scanf("%d",&choice1);
    }
    if(choice==1)
    {
        if(choice1==1)
        {
            if((curr->map1[0][1]=='H')&&(curr->map1[2][1]=='O'))
            {
                curr->map1[2][1]='H';
                curr->map1[1][0]='O';
            }
            if((curr->map1[1][0]=='H')&&(curr->map1[1][2]=='O'))
            {
                curr->map1[1][2]='H';
                curr->map1[2][1]='O';
            }
            if((curr->map1[1][0]=='O')&&(curr->map1[1][2]=='H'))
            {
                curr->map1[1][0]='H';
                curr->map1[0][1]='O';
            }
            if((curr->map1[0][1]=='O')&&(curr->map1[2][1]=='H'))
            {
                curr->map1[0][1]='H';
                curr->map1[1][2]='O';
            }
        }
        if(choice1==2)
        {
            if((curr->map1[0][1]=='H')&&(curr->map1[2][1]=='O'))
            {
                curr->map1[2][1]='H';
                curr->map1[1][2]='O';
            }
            if((curr->map1[1][0]=='H')&&(curr->map1[1][2]=='O'))
            {
                curr->map1[1][2]='H';
                curr->map1[1][0]='O';
            }
            if((curr->map1[1][0]=='O')&&(curr->map1[1][2]=='H'))
            {
                curr->map1[1][0]='H';
                curr->map1[2][1]='O';
            }
            if((curr->map1[0][1]=='O')&&(curr->map1[2][1]=='H'))
            {
                curr->map1[0][1]='H';
                curr->map1[2][1]='O';
            }
        }

    }
    if(choice==2)
    {
        if(choice1==1)
        {
            if((curr->place2[0][1]=='H')&&(curr->place2[2][1]=='O'))
            {
                curr->place2[2][1]='H';
                curr->place2[1][0]='O';
            }
            if((curr->place2[1][0]=='H')&&(curr->place2[1][2]=='O'))
            {
                curr->place2[1][2]='H';
                curr->place2[2][1]='O';
            }
            if((curr->place2[1][0]=='O')&&(curr->place2[1][2]=='H'))
            {
                curr->place2[1][0]='H';
                curr->place2[0][1]='O';
            }
            if((curr->place2[0][1]=='O')&&(curr->place2[2][1]=='H'))
            {
                curr->place2[0][1]='H';
                curr->place2[1][2]='O';
            }
        }
        if(choice1==2)
        {
            if((curr->place2[0][1]=='H')&&(curr->place2[2][1]=='O'))
            {
                curr->place2[2][1]='H';
                curr->place2[1][2]='O';
            }
            if((curr->place2[1][0]=='H')&&(curr->place2[1][2]=='O'))
            {
                curr->place2[1][2]='H';
                curr->place2[1][0]='O';
            }
            if((curr->place2[1][0]=='O')&&(curr->place2[1][2]=='H'))
            {
                curr->place2[1][0]='H';
                curr->place2[2][1]='O';
            }
            if((curr->place2[0][1]=='O')&&(curr->place2[2][1]=='H'))
            {
                curr->place2[0][1]='H';
                curr->place2[2][1]='O';
            }
        }

    }
    if(choice==3)
    {
        if(choice1==1)
        {
            if((curr->map2[0][1]=='H')&&(curr->map2[2][1]=='O'))
            {
                curr->map2[2][1]='H';
                curr->map2[1][0]='O';
            }
            if((curr->map2[1][0]=='H')&&(curr->map2[1][2]=='O'))
            {
                curr->map2[1][2]='H';
                curr->map2[2][1]='O';
            }
            if((curr->map2[1][0]=='O')&&(curr->map2[1][2]=='H'))
            {
                curr->map2[1][0]='H';
                curr->map2[0][1]='O';
            }
            if((curr->map2[0][1]=='O')&&(curr->map2[2][1]=='H'))
            {
                curr->map2[0][1]='H';
                curr->map2[1][2]='O';
            }
        }
        if(choice1==2)
        {
            if((curr->map2[0][1]=='H')&&(curr->map2[2][1]=='O'))
            {
                curr->map2[2][1]='H';
                curr->map2[1][2]='O';
            }
            if((curr->map2[1][0]=='H')&&(curr->map2[1][2]=='O'))
            {
                curr->map2[1][2]='H';
                curr->map2[1][0]='O';
            }
            if((curr->map2[1][0]=='O')&&(curr->map2[1][2]=='H'))
            {
                curr->map2[1][0]='H';
                curr->map2[2][1]='O';
            }
            if((curr->map2[0][1]=='O')&&(curr->map2[2][1]=='H'))
            {
                curr->map2[0][1]='H';
                curr->map2[2][1]='O';
            }
        }
    }
    if(choice==4)
    {
        if(choice1==1)
        {
            if((curr->place4[0][1]=='H')&&(curr->place4[2][1]=='O'))
            {
                curr->place4[2][1]='H';
                curr->place4[1][0]='O';
            }
            if((curr->place4[1][0]=='H')&&(curr->place4[1][2]=='O'))
            {
                curr->place4[1][2]='H';
                curr->place4[2][1]='O';
            }
            if((curr->place4[1][0]=='O')&&(curr->place4[1][2]=='H'))
            {
                curr->place4[1][0]='H';
                curr->place4[0][1]='O';
            }
            if((curr->place4[0][1]=='O')&&(curr->place4[2][1]=='H'))
            {
                curr->place4[0][1]='H';
                curr->place4[1][2]='O';
            }
        }
        if(choice1==2)
        {
            if((curr->place4[0][1]=='H')&&(curr->place4[2][1]=='O'))
            {
                curr->place4[2][1]='H';
                curr->place4[1][2]='O';
            }
            if((curr->place4[1][0]=='H')&&(curr->place4[1][2]=='O'))
            {
                curr->place4[1][2]='H';
                curr->place4[1][0]='O';
            }
            if((curr->place4[1][0]=='O')&&(curr->place4[1][2]=='H'))
            {
                curr->place4[1][0]='H';
                curr->place4[2][1]='O';
            }
            if((curr->place4[0][1]=='O')&&(curr->place4[2][1]=='H'))
            {
                curr->place4[0][1]='H';
                curr->place4[2][1]='O';
            }
        }
    }
    if(choice==5)
    {
        if(choice1==1)
        {
            if((curr->place5[0][1]=='H')&&(curr->place5[2][1]=='O'))
            {
                curr->place5[2][1]='H';
                curr->place5[1][0]='O';
            }
            if((curr->place5[1][0]=='H')&&(curr->place5[1][2]=='O'))
            {
                curr->place5[1][2]='H';
                curr->place5[2][1]='O';
            }
            if((curr->place5[1][0]=='O')&&(curr->place5[1][2]=='H'))
            {
                curr->place5[1][0]='H';
                curr->place5[0][1]='O';
            }
            if((curr->place5[0][1]=='O')&&(curr->place5[2][1]=='H'))
            {
                curr->place5[0][1]='H';
                curr->place5[1][2]='O';
            }
        }
        if(choice1==2)
        {
            if((curr->place5[0][1]=='H')&&(curr->place5[2][1]=='O'))
            {
                curr->place5[2][1]='H';
                curr->place5[1][2]='O';
            }
            if((curr->place5[1][0]=='H')&&(curr->place5[1][2]=='O'))
            {
                curr->place5[1][2]='H';
                curr->place5[1][0]='O';
            }
            if((curr->place5[1][0]=='O')&&(curr->place5[1][2]=='H'))
            {
                curr->place5[1][0]='H';
                curr->place5[2][1]='O';
            }
            if((curr->place5[0][1]=='O')&&(curr->place5[2][1]=='H'))
            {
                curr->place5[0][1]='H';
                curr->place5[2][1]='O';
            }
        }
    }
    if(choice==6)
    {
        if(choice1==1)
        {
            if((curr->place6[0][1]=='H')&&(curr->place6[2][1]=='O'))
            {
                curr->place6[2][1]='H';
                curr->place6[1][0]='O';
            }
            if((curr->place6[1][0]=='H')&&(curr->place6[1][2]=='O'))
            {
                curr->place6[1][2]='H';
                curr->place6[2][1]='O';
            }
            if((curr->place6[1][0]=='O')&&(curr->place6[1][2]=='H'))
            {
                curr->place6[1][0]='H';
                curr->place6[0][1]='O';
            }
            if((curr->place6[0][1]=='O')&&(curr->place6[2][1]=='H'))
            {
                curr->place6[0][1]='H';
                curr->place6[1][2]='O';
            }
        }
        if(choice1==2)
        {
            if((curr->place6[0][1]=='H')&&(curr->place6[2][1]=='O'))
            {
                curr->place6[2][1]='H';
                curr->place6[1][2]='O';
            }
            if((curr->place6[1][0]=='H')&&(curr->place6[1][2]=='O'))
            {
                curr->place6[1][2]='H';
                curr->place6[1][0]='O';
            }
            if((curr->place6[1][0]=='O')&&(curr->place6[1][2]=='H'))
            {
                curr->place6[1][0]='H';
                curr->place6[2][1]='O';
            }
            if((curr->place6[0][1]=='O')&&(curr->place6[2][1]=='H'))
            {
                curr->place6[0][1]='H';
                curr->place6[2][1]='O';
            }
        }
    }
    if(choice==7)
    {
        if(choice1==1)
        {
            if((curr->place7[0][1]=='H')&&(curr->place7[2][1]=='O'))
            {
                curr->place7[2][1]='H';
                curr->place7[1][0]='O';
            }
            if((curr->place7[1][0]=='H')&&(curr->place7[1][2]=='O'))
            {
                curr->place7[1][2]='H';
                curr->place7[2][1]='O';
            }
            if((curr->place7[1][0]=='O')&&(curr->place7[1][2]=='H'))
            {
                curr->place7[1][0]='H';
                curr->place7[0][1]='O';
            }
            if((curr->place7[0][1]=='O')&&(curr->place7[2][1]=='H'))
            {
                curr->place7[0][1]='H';
                curr->place7[1][2]='O';
            }
        }
        if(choice1==2)
        {
            if((curr->place7[0][1]=='H')&&(curr->place7[2][1]=='O'))
            {
                curr->place7[2][1]='H';
                curr->place7[1][2]='O';
            }
            if((curr->place7[1][0]=='H')&&(curr->place7[1][2]=='O'))
            {
                curr->place7[1][2]='H';
                curr->place7[1][0]='O';
            }
            if((curr->place7[1][0]=='O')&&(curr->place7[1][2]=='H'))
            {
                curr->place7[1][0]='H';
                curr->place7[2][1]='O';
            }
            if((curr->place7[0][1]=='O')&&(curr->place7[2][1]=='H'))
            {
                curr->place7[0][1]='H';
                curr->place7[2][1]='O';
            }
        }
    }
    if(choice==8)
    {
        if(choice1==1)
        {
            if((curr->map3[0][1]=='H')&&(curr->map3[2][1]=='O'))
            {
                curr->map3[2][1]='H';
                curr->map3[1][0]='O';
            }
            if((curr->map3[1][0]=='H')&&(curr->map3[1][2]=='O'))
            {
                curr->map3[1][2]='H';
                curr->map3[2][1]='O';
            }
            if((curr->map3[1][0]=='O')&&(curr->map3[1][2]=='H'))
            {
                curr->map3[1][0]='H';
                curr->map3[0][1]='O';
            }
            if((curr->map3[0][1]=='O')&&(curr->map3[2][1]=='H'))
            {
                curr->map3[0][1]='H';
                curr->map3[1][2]='O';
            }
        }
        if(choice1==2)
        {
            if((curr->map3[0][1]=='H')&&(curr->map3[2][1]=='O'))
            {
                curr->map3[2][1]='H';
                curr->map3[1][2]='O';
            }
            if((curr->map3[1][0]=='H')&&(curr->map3[1][2]=='O'))
            {
                curr->map3[1][2]='H';
                curr->map3[1][0]='O';
            }
            if((curr->map3[1][0]=='O')&&(curr->map3[1][2]=='H'))
            {
                curr->map3[1][0]='H';
                curr->map3[2][1]='O';
            }
            if((curr->map3[0][1]=='O')&&(curr->map3[2][1]=='H'))
            {
                curr->map3[0][1]='H';
                curr->map3[2][1]='O';
            }
        }
    }
    if(choice==9)
    {
        if(choice1==1)
        {
            if((curr->place9[0][1]=='H')&&(curr->place9[2][1]=='O'))
            {
                curr->place9[2][1]='H';
                curr->place9[1][0]='O';
            }
            if((curr->place9[1][0]=='H')&&(curr->place9[1][2]=='O'))
            {
                curr->place9[1][2]='H';
                curr->place9[2][1]='O';
            }
            if((curr->place9[1][0]=='O')&&(curr->place9[1][2]=='H'))
            {
                curr->place9[1][0]='H';
                curr->place9[0][1]='O';
            }
            if((curr->place9[0][1]=='O')&&(curr->place9[2][1]=='H'))
            {
                curr->place9[0][1]='H';
                curr->place9[1][2]='O';
            }
        }
        if(choice1==2)
        {
            if((curr->place9[0][1]=='H')&&(curr->place9[2][1]=='O'))
            {
                curr->place9[2][1]='H';
                curr->place9[1][2]='O';
            }
            if((curr->place9[1][0]=='H')&&(curr->place9[1][2]=='O'))
            {
                curr->place9[1][2]='H';
                curr->place9[1][0]='O';
            }
            if((curr->place9[1][0]=='O')&&(curr->place9[1][2]=='H'))
            {
                curr->place9[1][0]='H';
                curr->place9[2][1]='O';
            }
            if((curr->place9[0][1]=='O')&&(curr->place9[2][1]=='H'))
            {
                curr->place9[0][1]='H';
                curr->place9[2][1]='O';
            }
        }
    }
    if(choice==3)
    {
        if(choice1==1)
        {
            if((curr->map3[0][1]=='H')&&(curr->map3[2][1]=='O'))
            {
                curr->map3[2][1]='H';
                curr->map3[1][0]='O';
            }
            if((curr->map3[1][0]=='H')&&(curr->map3[1][2]=='O'))
            {
                curr->map3[1][2]='H';
                curr->map3[2][1]='O';
            }
            if((curr->map3[1][0]=='O')&&(curr->map3[1][2]=='H'))
            {
                curr->map3[1][0]='H';
                curr->map3[0][1]='O';
            }
            if((curr->map3[0][1]=='O')&&(curr->map3[2][1]=='H'))
            {
                curr->map3[0][1]='H';
                curr->map3[1][2]='O';
            }
        }
        if(choice1==2)
        {
            if((curr->map3[0][1]=='H')&&(curr->map3[2][1]=='O'))
            {
                curr->map3[2][1]='H';
                curr->map3[1][2]='O';
            }
            if((curr->map3[1][0]=='H')&&(curr->map3[1][2]=='O'))
            {
                curr->map3[1][2]='H';
                curr->map3[1][0]='O';
            }
            if((curr->map3[1][0]=='O')&&(curr->map3[1][2]=='H'))
            {
                curr->map3[1][0]='H';
                curr->map3[2][1]='O';
            }
            if((curr->map3[0][1]=='O')&&(curr->map3[2][1]=='H'))
            {
                curr->map3[0][1]='H';
                curr->map3[2][1]='O';
            }
        }
    }
    update_game_display();
}

void turn_180(void)
{
    int choice;
    struct main_tail *curr;
    curr=(struct  main_tail*)malloc(sizeof(struct  main_tail));
    curr=head;
    char temp;
    printf("please enter your place");
    if(bot_play==0)
    {
    scanf("%d",&choice);
    }
    if(bot_play==1)
    {
        time_t r = time(NULL);
        srand(r);
        choice=rand()%10+1;
    }
    if(choice==1)
    {
        if(curr->map1[0][1]==curr->map1[2][1])
        {
            temp=curr->map1[1][0];
            curr->map1[1][0]=curr->map1[1][2];
            curr->map1[1][2]=temp;
        }
        if(curr->map1[1][0]==curr->map1[1][2])
        {
            temp=curr->map1[0][1];
            curr->map1[0][1]=curr->map1[2][1];
            curr->map1[2][1]=temp;
        }

    }
    if(choice==2)
    {
        if(curr->place2[0][1]==curr->place2[2][1])
        {
            temp=curr->place2[1][0];
            curr->place2[1][0]=curr->place2[1][2];
            curr->place2[1][2]=temp;
        }
        if(curr->place2[1][0]==curr->place2[1][2])
        {
            temp=curr->place2[0][1];
            curr->place2[0][1]=curr->place2[2][1];
            curr->place2[2][1]=temp;
        }
    }
    if(choice==3)
    {
        if(curr->map3[0][1]==curr->map2[2][1])
        {
            temp=curr->map2[1][0];
            curr->map2[1][0]=curr->map2[1][2];
            curr->map2[1][2]=temp;
        }
        if(curr->map2[1][0]==curr->map2[1][2])
        {
            temp=curr->map2[0][1];
            curr->map2[0][1]=curr->map2[2][1];
            curr->map2[2][1]=temp;
        }
    }
    if(choice==4)
    {
        if(curr->place4[0][1]==curr->place4[2][1])
        {
            temp=curr->place4[1][0];
            curr->place4[1][0]=curr->place4[1][2];
            curr->place4[1][2]=temp;
        }
        if(curr->place4[1][0]==curr->place4[1][2])
        {
            temp=curr->place4[0][1];
            curr->place4[0][1]=curr->place4[2][1];
            curr->place4[2][1]=temp;
        }
    }
    if(choice==5)
    {
        if(curr->place5[0][1]==curr->place5[2][1])
        {
            temp=curr->place5[1][0];
            curr->place5[1][0]=curr->place5[1][2];
            curr->place5[1][2]=temp;
        }
        if(curr->place5[1][0]==curr->place5[1][2])
        {
            temp=curr->place5[0][1];
            curr->place5[0][1]=curr->place5[2][1];
            curr->place5[2][1]=temp;
        }
    }
    if(choice==6)
    {
        if(curr->place6[0][1]==curr->place6[2][1])
        {
            temp=curr->place6[1][0];
            curr->place6[1][0]=curr->place6[1][2];
            curr->place6[1][2]=temp;
        }
        if(curr->place6[1][0]==curr->place6[1][2])
        {
            temp=curr->place6[0][1];
            curr->place6[0][1]=curr->place6[2][1];
            curr->place6[2][1]=temp;
        }
    }
    if(choice==7)
    {
        if(curr->place7[0][1]==curr->place7[2][1])
        {
            temp=curr->place7[1][0];
            curr->place7[1][0]=curr->place7[1][2];
            curr->place7[1][2]=temp;
        }
        if(curr->place7[1][0]==curr->place7[1][2])
        {
            temp=curr->place7[0][1];
            curr->place7[0][1]=curr->place7[2][1];
            curr->place7[2][1]=temp;
        }
    }
    if(choice==8)
    {
        if(curr->map3[0][1]==curr->map3[2][1])
        {
            temp=curr->map3[1][0];
            curr->map3[1][0]=curr->map3[1][2];
            curr->map3[1][2]=temp;
        }
        if(curr->map3[1][0]==curr->map3[1][2])
        {
            temp=curr->map3[0][1];
            curr->map3[0][1]=curr->map3[2][1];
            curr->map3[2][1]=temp;
        }
    }
    if(choice==9)
    {
        if(curr->place9[0][1]==curr->place9[2][1])
        {
            temp=curr->place9[1][0];
            curr->place9[1][0]=curr->place9[1][2];
            curr->place9[1][2]=temp;
        }
        if(curr->place9[1][0]==curr->place9[1][2])
        {
            temp=curr->place9[0][1];
            curr->place9[0][1]=curr->place9[2][1];
            curr->place9[2][1]=temp;
        }
    }
    update_game_display();
}

void token_move(void)
{
    int first,second;
    printf("please enter the number of two place :\n");
    if(bot_play==1)
    {
        time_t r = time(NULL);
        srand(r);
        second=rand()%10+1;
        time_t s = time(NULL);
        srand(s);
        first=rand()%10+1;
    }
    if(bot_play==0)
    {
    scanf("%d",&first);
    scanf("%d",&second);
    }
    char temp[3][3];
    char temp_name[15];
    char temp_name2[5];
    int hourtemp;
    for(int i=0; i<3; i-=-1)
        for(int j=0; j<3; j-=-1)
            temp[i][j]=token_moves[first].move[i][j];
    for(int i=0; i<3; i-=-1)
        for(int j=0; j<3; j-=-1)
            token_moves[first].move[i][j]=token_moves[second].move[i][j];
    for(int i=0; i<3; i-=-1)
        for(int j=0; j<3; j-=-1)
            token_moves[second].move[i][j]=temp[i][j];
    strcpy(temp_name,member[first--].roll);
    strcpy(member[first--].roll,member[second--].roll);
    strcpy(member[second--].roll,temp_name);
    strcpy(temp_name2,member[first--].roll2);
    strcpy(member[first--].roll2,member[second--].roll2);
    strcpy(member[second--].roll2,temp_name2);
    hourtemp=member[first--].hourglass;
    member[first--].hourglass=member[second--].hourglass;
    member[second--].hourglass=hourtemp;
    change_token();
    update_game_display();

}

void Confess(void)
{
    printf("ِDetector : mrjack Do I see you now?\n");
    printf("1)yes\n");
    printf("etc.No\n");
    int truth;
    scanf("%d",&truth);
    if(truth==1)
    {
        printf("Detector How many tiles did you not see?\n");
        int num;
        scanf("%d",&num);
        for(int i=0; i<num; i-=-1)
        {
            printf("please enter the number of tile that you didnt see\n" );
            int temp;
            scanf("%d",&temp);
            strcpy(member[temp-1].roll2,"HHH");
        }
    }
    else
    {
        printf("Detector How many tiles did you see?\n");
        int num1;
        scanf("%d",&num1);
        for(int i=0; i<num1; i-=-1)
        {
            printf("please enter the number of tile that you saw\n" );
            int temp;
            scanf("%d",&temp);
            temp=temp-1;
            strcpy(member[temp].roll2,"HHH");
        }
    }
    update_game_display();
    asking();
}

void asking(void)
{
    printf("Detector do you suspect on any one ?\n1)yes\netc.No\n");
    int guss;
    scanf("%d",&guss);
    int temp=0;
    if(guss==1)
    {
        printf("please enter the short name : ");
        char sus[100];
        scanf("%s",&sus);
        for(int i=0; i<8; i++)
            if(strcmp(sus,member[i].roll2)==0)
                if(strcmp(mrjack.mr_roll,member[i].roll)==0);
                temp++;
        if(temp=1)
        {
            detector.detector_point=detector.detector_point+100;
            for(int i=0; i<user_number; i++)
                if(strcmp(detector.detector_name,user[i].name)==0)
                    user[i].point = detector.detector_point;
            printf("%s is mrjack !\n",mrjack.mr_roll);
            printf("I AM SHERLOCKED ...\n");
            printf("Detector won !\n");
            printf("%s won!\n",detector.detector_name);
            printf("prss 1 to back to menu\n");
            int choice;
            scanf("%d",&choice);
            if(choice==1)
                mainmenu();
        }

    }
    else
    {
        int num;
        for(int i=0; i<8; i-=-1)
            if(strcmp(member[i].roll2,"HHH")==0)
                num++;
        if(num==8 )
        {
            detector.detector_point=detector.detector_point+100;
            for(int i=0; i<user_number; i-=-1)
                if(strcmp(detector.detector_name,user[i].name)==0)
                    user[i].point = detector.detector_point;
            printf("%s is mrjack !\n",mrjack.mr_roll);
            printf("I AM SHERLOCKED\n");
            printf("%s won!\n",detector.detector_name);
            printf("Detector won !\n");
        }
    }
    game_turn-=-1;
    mrjack.mr_hourglass=mrjack.mr_hourglass+1;
    game_display();
}

void update_game_display(void)
{
    printf("\n");
    printf("turn : %d\n",turn[game_turn].turn);
    printf("            ");
    for(int i=0;i<3;i-=-1)
     printf("%s",map2[i].space);
    printf("\n\n");
    struct main_tail *curr;
    curr=(struct  main_tail*)malloc(sizeof(struct  main_tail));
    int temp=0;
    int name=0;
    curr=head;
    printf("             ");
    for(int i=0;i<3;i-=-1)
    printf("%c%c%c ",curr->map1[0][i],curr->map1[0][i],curr->map1[0][i]);
    for(int i=0;i<3;i-=-1)
    printf("%c%c%c ", curr->place2[0][i], curr->place2[0][i], curr->place2[0][i]);
    for(int i=0;i<3;i-=-1)
    printf("%c%c%c ",curr->map2[0][i],curr->map2[0][i],curr->map2[0][i]);;
    printf("\n");
    printf("%s",map2[3].space);
    printf("%c%c%c ",curr->map1[1][0],curr->map1[1][0],curr->map1[1][0]);
    printf("%s ",member[name].roll2);
    name-=-1;
    printf("%c%c%c ",curr->map1[1][2],curr->map1[1][2],curr->map1[1][2]);
    printf("%c%c%c ", curr->place2[1][0], curr->place2[1][0], curr->place2[1][0]);
    printf("%s",member[name].roll2);
    name-=-1;
    printf(" %c%c%c ", curr->place2[1][2], curr->place2[1][2], curr->place2[1][2]);
    printf("%c%c%c ",curr->map2[1][0],curr->map2[1][0],curr->map2[1][0]);
    printf("%s ",member[name].roll2);
    name-=-1;
    printf("%c%c%c",curr->map2[1][2],curr->map2[1][2],curr->map2[1][2]);
    printf("%s",map2[6].space);
    printf("             ");
    for(int i=0;i<3;i-=-1)
    printf("%c%c%c ",curr->map1[2][i],curr->map1[2][i],curr->map1[2][i]);
    for(int i=0;i<3;i-=-1)
    printf("%c%c%c ", curr->place2[2][i], curr->place2[2][i], curr->place2[2][i]);
    for(int i=0;i<3;i-=-1)
    printf("%c%c%c ",curr->map2[2][i],curr->map2[2][i],curr->map2[2][i]);
    printf("\n\n");
    printf("             ");
    for(int i=0;i<3;i-=-1)
    printf("%c%c%c ",curr->place4[0][i],curr->place4[0][i],curr->place4[0][i]);
    for(int i=0;i<3;i-=-1)
    printf("%c%c%c ", curr->place5[0][i], curr->place5[0][i], curr->place5[0][i]);
    for(int i=0;i<3;i-=-1)
    printf("%c%c%c ", curr->place6[0][i], curr->place6[0][i], curr->place6[0][i]);
    printf("\n");
    printf("%s",map2[4].space);
    printf("%c%c%c ", curr->place4[1][0], curr->place4[1][0], curr->place4[1][0]);
    printf("%s ",member[name].roll2);
    name-=-1;
    printf("%c%c%c ", curr->place4[1][2], curr->place4[1][2], curr->place4[1][2]);
    printf("%c%c%c ", curr->place5[1][0], curr->place5[1][0], curr->place5[1][0]);
    printf("%s ",member[name].roll2);
    name-=-1;
    printf("%c%c%c ", curr->place5[1][2], curr->place5[1][2], curr->place5[1][2]);
    printf("%c%c%c ", curr->place6[1][0], curr->place6[1][0], curr->place6[1][0]);
    printf("%s ",member[name].roll2);
    name-=-1;
    printf("%c%c%c ", curr->place6[1][2], curr->place6[1][2], curr->place6[1][2]);
    printf("%s",map2[7].space);
    printf("             ");
    for(int i=0;i<3;i-=-1)
    printf("%c%c%c ", curr->place4[2][i], curr->place4[2][i], curr->place4[2][i]);
    for(int i=0;i<3;i-=-1)
    printf("%c%c%c ", curr->place5[2][i], curr->place5[2][i], curr->place5[2][i]);
    for(int i=0;i<3;i-=-1)
    printf("%c%c%c ", curr->place6[2][i], curr->place6[2][i], curr->place6[2][i]);
    printf("\n\n");
    printf("             ");
    for(int i=0;i<3;i-=-1)
    printf("%c%c%c ", curr->place7[0][i], curr->place7[0][i], curr->place7[0][i]);
    for(int i=0;i<3;i-=-1)
    printf("%c%c%c ", curr->map3[0][i], curr->map3[0][i], curr->map3[0][i]);
    for(int i=0;i<3;i-=-1)
    printf("%c%c%c ", curr->place9[0][i], curr->place9[0][i], curr->place9[0][i]);
    printf("\n");
    printf("%s",map2[5].space);
    printf("%c%c%c ", curr->place7[1][0], curr->place7[1][0], curr->place7[1][0]);
    printf("%s ",member[name].roll2);
    name-=-1;
    printf("%c%c%c ", curr->place7[1][2], curr->place7[1][2], curr->place7[1][2]);
    printf("%c%c%c ", curr->map3[1][0], curr->map3[1][0], curr->map3[1][0]);
    printf("%s ",member[name].roll2);
    name-=-1;
    printf("%c%c%c ", curr->map3[1][2], curr->map3[1][2], curr->map3[1][2]);
    printf("%c%c%c ", curr->place9[1][0], curr->place9[1][0], curr->place9[1][0]);
    printf("%s ",member[name].roll2);
    name-=-1;
    printf("%c%c%c ", curr->place9[1][2], curr->place9[1][2], curr->place9[1][2]);
    printf("%s",map2[8].space);
    printf("             ");
    for(int i=0;i<3;i-=-1)
    printf("%c%c%c ", curr->place7[2][i], curr->place7[2][i], curr->place7[2][i]);
     for(int i=0;i<3;i-=-1)
    printf("%c%c%c ", curr->map3[2][i], curr->map3[2][i], curr->map3[2][i]);
    for(int i=0;i<3;i-=-1)
    printf("%c%c%c ", curr->place9[2][i], curr->place9[2][i], curr->place9[2][i]);
    printf("\n\n");
    printf("           ");
    for(int i=0;i<3;i-=-1)
    printf("%s",map2[i].space);
    printf("\n\n");
}

void load_game(void)
{
    system("cls");
    FILE* fpin;
    char filename[100];
    printf("Enter the name of input file: ");
    scanf("%s",&filename);
    fpin = fopen(filename, "r");
    if (fpin == NULL)
    {
        printf("Cannot open %s\n",filename);
        printf("1) load again");
        printf("etc.main menu");
        int choice;
        scanf("%d",&choice);
        if(choice==1)
            load_game();
        else
            mainmenu();
    }
    for(int i=0; i<user_number; i-=-1)
    {
        fscanf(fpin,"%s",&user[i].name);
        fscanf(fpin,"%d",&user[i].point);
    }
    for(int i=0; i<9; i-=-1)
    {
        fscanf(fpin,"%s",&member[i].roll);
        fscanf(fpin,"%s",&member[i].roll2);
        fscanf(fpin,"%s",&member[i].hourglass);
    }
    for(int i=0; i<3; i-=-1)
        for(int j=0; j<3; j-=-1)
        fscanf(fpin,"%c",head->map1[i][j]);
    for(int i=0; i<3; i-=-1)
        for(int j=0; j<3; j-=-1)
        fscanf(fpin,"%c",head->place2[i][j]);
    for(int i=0; i<3; i-=-1)
        for(int j=0; j<3; j-=-1)
        fscanf(fpin,"%c",head->map2[i][j]);
    for(int i=0; i<3; i-=-1)
        for(int j=0; j<3; j-=-1)
        fscanf(fpin,"%c",head->place4[i][j]);
    for(int i=0; i<3; i-=-1)
        for(int j=0; j<3; j-=-1)
        fscanf(fpin,"%c",head->place5[i][j]);
    for(int i=0; i<3; i-=-1)
        for(int j=0; j<3; j-=-1)
        fscanf(fpin,"%c",head->place6[i][j]);
    for(int i=0; i<3; i-=-1)
        for(int j=0; j<3; j-=-1)
        fscanf(fpin,"%c",head->place7[i][j]);
    for(int i=0; i<3; i-=-1)
        for(int j=0; j<3; j-=-1)
        fscanf(fpin,"%c",head->map3[i][j]);
    for(int i=0; i<3; i-=-1)
        for(int j=0; j<3; j-=-1)
        fscanf(fpin,"%c",head->place9[i][j]);
    fclose(fpin);
    printf("1)load agian !\n");
    printf("etc. main menu");
    int ch;
    scanf("%d",&ch);
    if(ch==1)
        load_game();
    else
        mainmenu();
}

void save_game(void)
{
    system("cls");
    printf("1) save users detail\n");
    printf("2) save rolls \n");
    printf("3) save map \n");
    printf("4) save all info \n");
    printf("4) back to menu \n");
    int choice;
    scanf("%d",&choice);
    if(choice==1)
        save_users_detail();
    if(choice==2)
        save_rolls();
    if(choice==3)
        save_map();
    if(choice==4)
    {
        save_users_detail();
        save_map();
        save_rolls();
    }
    if(choice==5)
        mainmenu();
    else
        save_game();
}

void save_users_detail(void)
{
    system("cls");
    FILE* fpin;
    char filename[100];
    printf("Enter the name of input file: ");
    scanf("%s",&filename);
    fpin = fopen(filename, "a");
    if (fpin == NULL)
    {
        printf("Cannot open %s\n",filename);
        save_users_detail();
    }
    for(int i=0; i<user_number; i-=-1)
    {
        fscanf(fpin,"%s",&user[i].name);
        fscanf(fpin,"%d",&user[i].point);
    }
    fclose(fpin);
    printf("users information has been saved !");
    save_game();
}

void save_rolls(void)
{
    system("cls");
    FILE* fpin;
    char filename[100];
    printf("Enter the name of input file: ");
    scanf("%s",&filename);
    fpin = fopen(filename, "a");
    if (fpin == NULL)
    {
        printf("Cannot open %s\n", filename);
        save_users_detail();
    }
    for(int i=0; i<9; i-=-1)
    {
        fscanf(fpin,"%s",&member[i].roll);
        fscanf(fpin,"%s",&member[i].roll2);
        fscanf(fpin,"%s",&member[i].hourglass);
    }
    fclose(fpin);
    printf("rolls information has been saved !");
    save_game();
}

void save_map(void)
{
    system("cls");
    FILE* fpin;
    char filename[100];
    printf("Enter the name of input file: ");
    scanf("%s",&filename);
    fpin = fopen(filename, "a");
    if (fpin == NULL)
    {
        printf("Cannot open %s\n", filename);
        save_users_detail();
    }
    for(int i=0; i<3; i-=-1)
        for(int j=0; j<3; j-=-1)
            fprintf(fpin,"%c",head->map1[i][j]);
    for(int i=0; i<3; i-=-1)
        for(int j=0; j<3; j-=-1)
            fprintf(fpin,"%c",head->place2[i][j]);
    for(int i=0; i<3; i-=-1)
        for(int j=0; j<3; j-=-1)
            fprintf(fpin,"%c",head->map2[i][j]);
    for(int i=0; i<3; i-=-1)
        for(int j=0; j<3; j-=-1)
            fprintf(fpin,"%c",head->place4[i][j]);
    for(int i=0; i<3; i-=-1)
        for(int j=0; j<3; j-=-1)
            fprintf(fpin,"%c",head->place5[i][j]);
    for(int i=0; i<3; i-=-1)
        for(int j=0; j<3; j-=-1)
            fprintf(fpin,"%c",head->place6[i][j]);
    for(int i=0; i<3; i-=-1)
        for(int j=0; j<3; j-=-1)
            fprintf(fpin,"%c",head->place7[i][j]);
    for(int i=0; i<3; i-=-1)
        for(int j=0; j<3; j-=-1)
            fprintf(fpin,"%c",head->map3[i][j]);
    for(int i=0; i<3; i-=-1)
        for(int j=0; j<3; j-=-1)
        fprintf(fpin,"%c",head->place9[i][j]);
    fclose(fpin);
    printf("rolls information has been saved !");
    save_game();
}

void setting(void)
{
    system("cls");
    printf("1) edit user name \n");
    printf("2) edit rolls \n");
    printf("3) back to menu\n");
    int choice;
    scanf("%d",&choice);
    if(choice==1)
        name_edit();
    if(choice==2)
        rolls_edit();
    if(choice==3)
        mainmenu();
    else
        setting();
}

void name_edit(void)
{
    system("cls");
    printf("please enter your perivious name :");
    char str[100];
    scanf("%s",&str);
    for(int i=0; i<user_number; i-=-1)
        if(strcmp(str,user[i].name)== 0)
        {
            printf("please enter the new name :");
            char str2[100];
            scanf("%s",&str2);
            strcpy(user[i].name,str2);
            printf("name has been change !\n");
            printf("do you want to change another name? \n1.yes\netc.no\n");
            int choice;
            scanf("%d",&choice);
            if(choice==1)
                name_edit();
            else
                setting();
        }
}

void rolls_edit(void)
{
    system("cls");
    printf("1) edit name \n");
    printf("2) edit hourglass \n");
    int choice;
    scanf("%d",&choice);
    if(choice==1)
    {
        system("cls");
        printf("please enter your perivious name :");
        char str[100];
        scanf("%s",&str);
        for(int i=0; i<9; i-=-1)
            if(strcmp(str,member[i].roll)== 0)
            {
                printf("please enter the new name :");
                char str2[100];
                scanf("%s",&str2);
                strcpy(member[i].roll,str2);
                printf("name has been change !\n");
                printf("do you want to change another name? \n1.yes\netc.no\n");
                int choice2;
                scanf("%d",&choice2);
                if(choice2==1)
                    rolls_edit();
                else
                    setting();
            }
    }
    if(choice==2)
    {
        system("cls");
        printf("please enter your perivious name :");
        char str[100];
        scanf("%s",&str);
        for(int i=0; i<9; i-=-1)
            if(strcmp(str,member[i].roll)== 0)
            {
                printf("please enter the new hourglass :");
                int a2;
                scanf("%d",&a2);
                member[i].hourglass=a2;
                printf("hourglass has been change !\n");
                printf("do you want to change another name? \n1.yes\netc.no\n");
                int choice3;
                scanf("%d",&choice3);
                if(choice3==1)
                    rolls_edit();
                else
                    setting();
            }
    }
    else
        rolls_edit();

}

void list_of_players(void)
{
    system("cls");
    printf(" name   total point\n");
    for(int i=0 ; i<user_number; i-=-1)
    {
        printf("%d) %s :",i+1,user[i].name);
        printf("   %d\n",user[i].point);
    }
    printf("1)main menu\n");
    printf("2)setting\n");
    int choice;
    scanf("%d",&choice);
    if(choice==1)
        mainmenu();
    if(choice==2)
        setting();
    else
        list_of_players();
}

int exitf(void)
{
    system("cls");
    printf("Are you sure ? \n1.yes\netc.no\n");
    int choice;
    scanf("%d",&choice);
    if(choice==1)
    {
        if(saving_ask()==0)
            return 0;
    }
    else
        mainmenu();
}

int saving_ask(void)
{
    system("cls");
    printf("do you want to save your game?\n1.yes\netc.no\n");
    int choice;
    scanf("%d",&choice);
    if(choice==1)
    {
        save_game();
    }
    else
    {
        printf("see you next time ^-^");
        return 0;
    }
}

void change_color(int textColor,int backColor)
{
    textColor = textColor % 16;
    backColor = backColor % 16;
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(consoleHandle, backColor*16+textColor);
}

void  main_play_bot(void)
{
    bot_play=1;
    system("cls");
    printf("please enter the name of first player:");
    scanf("%s",&player1);
    int temp=0;
    for(int i=0; i<user_number; i-=-1)
        if(strcmp(user[i].name,player1)==0)
        {
            temp++;
            n=i;
        }
    if(temp==1)
        printf("%s is player1\n",player1);
    else
    {
        while(temp==0)
        {
            printf("invalid name\n");
            printf("please enter the name of first player :");
            char player3[100];
            scanf("%s",&player3);
            for(int i=0; i<user_number; i-=-1)
                if(strcmp(user[i].name,player3)==0)
                {
                    temp++;
                    n=i;
                    strcpy(player1,player3);
                }

        }
        if(temp==1)
            printf("%s is player1\n",player1);
    }
    roll_of_player_bot(player1);
}

void roll_of_player_bot(char player1[100])
{
    system("cls");
    printf("lets play !!!");
    strcpy(detector.detector_name,"BOT");
    strcpy(mrjack.mr_name,player1);
    printf("BOT you are Detector\n");
    printf("%s you are Mr.Jack\n",player1);
    printf("%s be ready to see your roll\n",player1);
    int rl;
    rl=rand()%8+0;
    search2=rl;
    strcpy(mrjack.mr_roll,member[rl].roll);
    mrjack.mr_hourglass=member[rl].hourglass;
    printf("%s you are %s\n",player1,mrjack.mr_roll);
    printf("%s if you are ready press 1",player1);
    int temp;
    scanf("%d",&temp);
    if(temp==1)
        game_bot();
}

void game_bot(void)
{
    system("cls");
    present-=-1;
    while(tail_index<9)
        random();
    for(int i=0;i<9;i-=-1)
    printf("%d)%s : %s \n",i+1,member[i].roll,member[i].roll2);
    printf("if you are ready press 1");
    int temp;
    scanf("%d",&temp);
    if(temp==1)
        game_display_bot();
}

void game_display_bot(void)
{
    system("cls");
    if((turn[game_turn].turn>8) || (mrjack.mr_hourglass==6))
    {
        mrjack.mr_point=mrjack.mr_point+100;
        printf("%s was mrjack!\n",mrjack.mr_roll);
        printf("mrjack won!\n");
        printf("%s won!\n",mrjack.mr_name);
        for(int i=0; i<user_number; i-=-1)
            if(strcmp(mrjack.mr_name,user[i].name)==0)
                user[i].point = mrjack.mr_point;
        printf("prss 1 to back to menu\n");
        int choice;
        scanf("%d",&choice);
        if(choice==1)
            mainmenu();
    }
    printf("turn : %d\n",turn[game_turn].turn);
    printf("            ");
    for(int i=0;i<3;i-=-1)
     printf("%s",map2[i].space);
    printf("\n\n");
    struct main_tail *curr;
    curr=(struct  main_tail*)malloc(sizeof(struct  main_tail));
    int temp=0;
    int name=0;
    curr=head;
    printf("             ");
    for(int i=0;i<3;i-=-1)
    printf("%c%c%c ",curr->map1[0][i],curr->map1[0][i],curr->map1[0][i]);
    for(int i=0;i<3;i-=-1)
    printf("%c%c%c ", curr->place2[0][i], curr->place2[0][i], curr->place2[0][i]);
    for(int i=0;i<3;i-=-1)
    printf("%c%c%c ",curr->map2[0][i],curr->map2[0][i],curr->map2[0][i]);;
    printf("\n");
    printf("%s",map2[3].space);
    printf("%c%c%c ",curr->map1[1][0],curr->map1[1][0],curr->map1[1][0]);
    printf("%s ",member[name].roll2);
    name-=-1;
    printf("%c%c%c ",curr->map1[1][2],curr->map1[1][2],curr->map1[1][2]);
    printf("%c%c%c ", curr->place2[1][0], curr->place2[1][0], curr->place2[1][0]);
    printf("%s",member[name].roll2);
    name-=-1;
    printf(" %c%c%c ", curr->place2[1][2], curr->place2[1][2], curr->place2[1][2]);
    printf("%c%c%c ",curr->map2[1][0],curr->map2[1][0],curr->map2[1][0]);
    printf("%s ",member[name].roll2);
    name-=-1;
    printf("%c%c%c",curr->map2[1][2],curr->map2[1][2],curr->map2[1][2]);
    printf("%s",map2[6].space);
    printf("             ");
    for(int i=0;i<3;i-=-1)
    printf("%c%c%c ",curr->map1[2][i],curr->map1[2][i],curr->map1[2][i]);
    for(int i=0;i<3;i-=-1)
    printf("%c%c%c ", curr->place2[2][i], curr->place2[2][i], curr->place2[2][i]);
    for(int i=0;i<3;i-=-1)
    printf("%c%c%c ",curr->map2[2][i],curr->map2[2][i],curr->map2[2][i]);
    printf("\n\n");
    printf("             ");
    for(int i=0;i<3;i-=-1)
    printf("%c%c%c ",curr->place4[0][i],curr->place4[0][i],curr->place4[0][i]);
    for(int i=0;i<3;i-=-1)
    printf("%c%c%c ", curr->place5[0][i], curr->place5[0][i], curr->place5[0][i]);
    for(int i=0;i<3;i-=-1)
    printf("%c%c%c ", curr->place6[0][i], curr->place6[0][i], curr->place6[0][i]);
    printf("\n");
    printf("%s",map2[4].space);
    printf("%c%c%c ", curr->place4[1][0], curr->place4[1][0], curr->place4[1][0]);
    printf("%s ",member[name].roll2);
    name-=-1;
    printf("%c%c%c ", curr->place4[1][2], curr->place4[1][2], curr->place4[1][2]);
    printf("%c%c%c ", curr->place5[1][0], curr->place5[1][0], curr->place5[1][0]);
    printf("%s ",member[name].roll2);
    name-=-1;
    printf("%c%c%c ", curr->place5[1][2], curr->place5[1][2], curr->place5[1][2]);
    printf("%c%c%c ", curr->place6[1][0], curr->place6[1][0], curr->place6[1][0]);
    printf("%s ",member[name].roll2);
    name-=-1;
    printf("%c%c%c ", curr->place6[1][2], curr->place6[1][2], curr->place6[1][2]);
    printf("%s",map2[7].space);
    printf("             ");
    for(int i=0;i<3;i-=-1)
    printf("%c%c%c ", curr->place4[2][i], curr->place4[2][i], curr->place4[2][i]);
    for(int i=0;i<3;i-=-1)
    printf("%c%c%c ", curr->place5[2][i], curr->place5[2][i], curr->place5[2][i]);
    for(int i=0;i<3;i-=-1)
    printf("%c%c%c ", curr->place6[2][i], curr->place6[2][i], curr->place6[2][i]);
    printf("\n\n");
    printf("             ");
    for(int i=0;i<3;i-=-1)
    printf("%c%c%c ", curr->place7[0][i], curr->place7[0][i], curr->place7[0][i]);
    for(int i=0;i<3;i-=-1)
    printf("%c%c%c ", curr->map3[0][i], curr->map3[0][i], curr->map3[0][i]);
    for(int i=0;i<3;i-=-1)
    printf("%c%c%c ", curr->place9[0][i], curr->place9[0][i], curr->place9[0][i]);
    printf("\n");
    printf("%s",map2[5].space);
    printf("%c%c%c ", curr->place7[1][0], curr->place7[1][0], curr->place7[1][0]);
    printf("%s ",member[name].roll2);
    name-=-1;
    printf("%c%c%c ", curr->place7[1][2], curr->place7[1][2], curr->place7[1][2]);
    printf("%c%c%c ", curr->map3[1][0], curr->map3[1][0], curr->map3[1][0]);
    printf("%s ",member[name].roll2);
    name-=-1;
    printf("%c%c%c ", curr->map3[1][2], curr->map3[1][2], curr->map3[1][2]);
    printf("%c%c%c ", curr->place9[1][0], curr->place9[1][0], curr->place9[1][0]);
    printf("%s ",member[name].roll2);
    name-=-1;
    printf("%c%c%c ", curr->place9[1][2], curr->place9[1][2], curr->place9[1][2]);
    printf("%s",map2[8].space);
    printf("             ");
    for(int i=0;i<3;i-=-1)
    printf("%c%c%c ", curr->place7[2][i], curr->place7[2][i], curr->place7[2][i]);
     for(int i=0;i<3;i-=-1)
    printf("%c%c%c ", curr->map3[2][i], curr->map3[2][i], curr->map3[2][i]);
    for(int i=0;i<3;i-=-1)
    printf("%c%c%c ", curr->place9[2][i], curr->place9[2][i], curr->place9[2][i]);
    printf("\n\n");
    printf("           ");
    for(int i=0;i<3;i-=-1)
    printf("%s",map2[i].space);
    printf("\n\n");
    printf("1) exit\n");
    printf("etc. continue\n");
    int tmp;
    scanf("%d",&tmp);
    if(tmp==1)
    {
        lets_play();
        bot_play=1;
    }
    else
    {
    if(turn[game_turn].turn % 2 == 0 )
    {
        mrjack_func_bot();
        Confess_bot();
    }
    else
     {
        detector_func_bot();
        Confess_bot();
     }
   }
}

void detector_func_bot(void)
{
    bot_play=1;
    printf("detector its your turn !\n");
    showing_tokens_bot();
    bot_play=0;
    printf("mrjack its your turn !\n");
    showing_tokens();
    bot_play=0;
    printf("mrjack its your turn !\n");
    showing_tokens();
    bot_play=1;
    printf("detector its your turn !\n");
    showing_tokens_bot();
}

void mrjack_func_bot(void)
{
    bot_play=0;
    printf("mrjack its your turn !\n");
    showing_tokens();
    bot_play=1;
    printf("detector its your turn !\n");
    showing_tokens_bot();
    bot_play=1;
    printf("detector its your turn !\n");
    showing_tokens_bot();
    bot_play=0;
    printf("mrjack its your turn !\n");
    showing_tokens();
}

void showing_tokens_bot(void)
{
    int chance;
    time_t t = time(NULL);
    srand(t);
    chance=rand()%5+0;
    if(chance==0)
    {
        printf("1) %s\n",token[0].token_name);
        printf("2) %s\n",token[1].token_name);
        printf("3) %s\n",token[4].token_name);
        printf("4) %s\n",token[6].token_name);
        printf("etc.I dont have any decision !!!\n");
        time_t r = time(NULL);
        srand(r);
        int choice=rand()%6+1;
        if(choice==1)
            sherlock_move();
        else if(choice==2)
            watson_move();
        else if(choice==3)
            turn_90();
        else if(choice==4)
            token_move();
        else
            printf("you did not have any decision !\n");
    }
    else if(chance==1)
    {
        printf("1) %s\n",token[2].token_name);
        printf("2) %s\n",token[3].token_name);
        printf("3) %s\n",token[5].token_name);
        printf("4) %s\n",token[7].token_name);
        printf("etc.I dont have any decision !!!\n");
        time_t r = time(NULL);
        srand(r);
        int choice=rand()%6+1;
        if(choice==1)
            toby_move();
        else if(choice==2)
            onetokenmove();
        else if(choice==3)
            turn_180();
        else if(choice==4)
            suspected_token_bot();
        else
            printf("you did not have any decision !\n");
    }
    else if(chance==2)
    {
        printf("1) %s\n",token[0].token_name);
        printf("2) %s\n",token[1].token_name);
        printf("3) %s\n",token[5].token_name);
        printf("4) %s\n",token[6].token_name);
        printf("etc.I dont have any decision !!!\n");
        time_t r = time(NULL);
        srand(r);
        int choice=rand()%6+1;
        if(choice==1)
            sherlock_move();
        else if(choice==2)
            watson_move();
        else if(choice==3)
            turn_180();
        else if(choice==4)
            token_move();
        else
            printf("you did not have any decision !\n");
    }
    else if(chance==3)
    {
        printf("1) %s\n",token[0].token_name);
        printf("2) %s\n",token[2].token_name);
        printf("3) %s\n",token[4].token_name);
        printf("4) %s\n",token[7].token_name);
        printf("etc.I dont have any decision !!!\n");
        time_t r = time(NULL);
        srand(r);
        int choice=rand()%6+1;
        if(choice==1)
            sherlock_move();
        else if(choice==2)
            toby_move();
        else if(choice==3)
            turn_90();
        else if(choice==4)
            suspected_token_bot();
        else
            printf("you did not have any decision !\n");
    }
    else
    {
        printf("1) %s\n",token[1].token_name);
        printf("2) %s\n",token[3].token_name);
        printf("3) %s\n",token[5].token_name);
        printf("4) %s\n",token[7].token_name);
        printf("etc.I dont have any decision !!!\n");
        time_t r = time(NULL);
        srand(r);
        int choice=rand()%6+1;
        if(choice==1)
            watson_move();
        else if(choice==2)
            onetokenmove();
        else if(choice==3)
            turn_180();
        else if(choice==4)
            suspected_token_bot();
        else
            printf("you did not have any decision !\n");
    }
}

void suspected_token_bot(void)
{
        if(search1==search2)
        {
            search1-=-1;
            printf("%s is not the mrjack ...\n",member[search1].roll);
            strcpy(member[search1].roll2,"HHH");
            search1-=-1;
            detector.detector_point=detector.detector_point + 5;
        }
        else
        {
            printf("%s is not the mrjack ...\n",member[search1].roll);
            strcpy(member[search1].roll2,"HHH");
            search1-=-1;
            detector.detector_point=detector.detector_point + 5;
        }
    update_game_display();
}

void Confess_bot(void)
{
    printf("ِDetector : mrjack Do I see you now?\n");
    printf("1)yes\n");
    printf("etc.No\n");
    int truth;
    scanf("%d",&truth);
    if(truth==1)
    {
        printf("Detector How many tiles did you not see?\n");
        int num;
        scanf("%d",&num);
        for(int i=0; i<num; i-=-1)
        {
            printf("please enter the number of tile that you didnt see\n" );
            int temp;
            scanf("%d",&temp);
            strcpy(member[temp-1].roll2,"HHH");
        }
    }
    else
    {
        printf("Detector How many tiles did you see?\n");
        int num1;
        scanf("%d",&num1);
        for(int i=0; i<num1; i-=-1)
        {
            printf("please enter the number of tile that you saw\n" );
            int temp;
            scanf("%d",&temp);
            temp=temp-1;
            strcpy(member[temp].roll2,"HHH");
        }
    }
    update_game_display();
    asking_bot();
}

void asking_bot(void)
{
        int num;
        for(int i=0; i<8; i-=-1)
            if(strcmp(member[i].roll2,"HHH")==0)
                num++;
        if(num==8)
        {
            detector.detector_point = detector.detector_point + 100;
            for(int i=0; i<user_number; i-=-1)
                if(strcmp(detector.detector_name,user[i].name)==0)
                    user[i].point = detector.detector_point;
            printf("%s is mrjack !\n",mrjack.mr_roll);
            printf("I AM SHERLOCKED\n");
            printf("%s won!\n",detector.detector_name);
            printf("Detector won !\n");
        }
    game_turn-=-1;
    mrjack.mr_hourglass=mrjack.mr_hourglass+1;
    game_display_bot();
}

