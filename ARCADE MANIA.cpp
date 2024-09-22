#include <stdio.h>  
#include <conio.h>      // for snake
#include <time.h>       // for rockpaperscissor & snake & wordle
#include <stdlib.h>     // for rockpaperscissor & wordle & snake
#include <string.h>     // for wordle 
#include<ctype.h>       // for snake
#include <windows.h>    // for snake
#include <process.h>    // for snake
#include <stdbool.h>    // for wordle

// for snake
#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77

// for wordle
#define MAX_ATTEMPTS 6

// code for wordle
const char* word_list[] = {"apple","banana","cherry","grape","lemon","orange","litchi","mango"};
const char* getRandomWord() {
    int num_words = sizeof(word_list) / sizeof(word_list[0]);   // Determine the number of words in the word list
    int index = rand() % num_words;      //Generate a random index to select a word from the list
    return word_list[index];
}
void displayWord(const char* target_word, const bool* guessed) {
     // Display the word with guessed letters revealed and others as underscores
    for (int i = 0; target_word[i] != '\0'; i++) {
        if (guessed[i]) {
            printf("%c ", target_word[i]);
        } else {
            printf("_ ");
        }
    }
    printf("\n");
}
int wordle() {

    srand(time(NULL));
    const char* target_word = getRandomWord();
    int word_length = strlen(target_word);
    bool guessed[MAX_ATTEMPTS];
    int attempts = 0;
    for (int i = 0; i < word_length; i++) {
        guessed[i] = false;
    }
    printf("Welcome to Fruit wordle!\n");
    printf("PLEASE ENTER ONLY ONE LETTER AT A TIME\n");
    printf("Enter a Fruit name:\nGuess the word: ");
    displayWord(target_word, guessed);
    while (attempts < MAX_ATTEMPTS) {
        char guess;
        printf("Enter a letter guess: ");
        scanf(" %c", &guess);
        bool found = false;
        for (int i = 0; i < word_length; i++) {
            if (!guessed[i] && target_word[i] == guess) {
                guessed[i] = true;
                found = true;
            }
        }
        if (found) {
            printf("Good guess!\n");
            displayWord(target_word, guessed);
        } else {
            printf("Incorrect guess. Attempts left: %d\n", MAX_ATTEMPTS - attempts - 1);
            attempts++;
        }
        bool all_guessed = true;
        for (int i = 0; i < word_length; i++) {
            if (!guessed[i]) {
                all_guessed = false;
                break;
            }
        }
        if (all_guessed) {
            printf("Congratulations! You guessed the word: %s\n", target_word);
            break;
        }
    }
    if (attempts == MAX_ATTEMPTS) {
        printf("Out of attempts! The word was: %s\n", target_word);
    }
    return 0;
}


// wordle ends here












//Code for tictactoe

 
// Globally declared 2D-array
char board[3][3];

int tictac();

// Function to initialize the game board
void initializeBoard()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            board[i][j] = ' ';
        }
    }
    int count = 1;
    printf("\n\n\t  ");
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            printf("%d", count++);
            if (j < 2)
            {
                printf("  |  ");
            }
        }
        if (i < 2)
        printf("\n\t----------------\n\t  ");
    }
    printf("\n\n\n");
}
 
// Function shows the game board
void showBoard(int x, int y)
{
    printf("\n\n\t  ");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%c", board[i][j]);
            if (j < 2)
            {
                printf("  |  ");
            }
        }
        if (i < 2)
        printf("\n\t----------------\n\t  ");
    }
    printf("\n\n\n");
}
 
// Function to update the game board
int updateBoard(int cell, char playerSign)
{
    int row = (cell - 1) / 3;
    int col = (cell - 1) % 3;
    int isValid = 1;
 
    // accessing already played cell number
    if (board[row][col] != ' ')
    {
        printf("\nInvalid: Cell is already Filled!\n");
        isValid = 0;
    }
 
    // valid cell position
    else
    {
        board[row][col] = playerSign;
    }
    showBoard(row, col);
 
    return isValid;
}
 
// Function to check the winner of the game
int checkWinner(char sg)
{
    // check all rows
    if (board[0][0] == sg && board[0][1] == sg && board[0][2] == sg ||
      board[1][0] == sg && board[1][1] == sg && board[1][2] == sg ||
      board[2][0] == sg && board[2][1] == sg && board[2][2] == sg)
    {
        return 1;
      }
      // check all columns
    else if (board[0][0] == sg && board[1][0] == sg && board[2][0] == sg ||
           board[0][1] == sg && board[1][1] == sg && board[2][1] == sg ||
           board[0][2] == sg && board[1][2] == sg && board[2][2] == sg)
    {
        return 1;
    }
    // check both diagonals
    else if (board[0][0] == sg && board[1][1] == sg && board[2][2] == sg ||
           board[0][2] == sg && board[1][1] == sg && board[2][0] == sg)
    {
        return 1;
    }
 
    // There is no winner
    return 0;
}
 
// Start your game from here
void playTicTacToe()
{
    int gameResult = 0;
    int cell = 0;
    int playCount = 0;
    int updationResult = 1;
 
    char playerSign = ' ';
 
    // start playing the game
    while (!gameResult && playCount < 9)
    {
        if (playCount % 2 == 0)
        {
            // player 1
            printf("\nPlayer 1 [ X ] : ");
            playerSign = 'X';
        }
        else
        {
            // player 2
            printf("\nPlayer 2 [ O ] : ");
            playerSign = 'O';
        }
        scanf("%d", &cell);
        if (cell > 0 && cell < 10)
        {
            updationResult = updateBoard(cell, playerSign);
            // if updation is possible
            if (updationResult)
            {
                gameResult = checkWinner(playerSign);
                // print the winner of the game
                if (gameResult)
                {
                    printf("\t *** Player %d Won!! ***\n", playerSign == 'X' ? 1 : 2);
                }
                playCount++;
            }
        }
        else if (cell == -1)
        {
            printf("\n\tGame Terminated\n");
            return;
        }
        else
        {
            printf("\nPlease Enter a valid cell value\n");
        }
    }
 
    // no one won the game
    if (!gameResult && playCount == 9)
    {
        printf("\n\t *** Draw...  ***\n");
    }
    printf("\n\t --- Game Over --- \n");
}
int tictac(){
    printf("--------- Tic Tac Toe ----------\n\n");
 
    printf("\n* Instructions \n\n");
    printf("\tPlayer 1 sign = X\n");
    printf("\tPlayer 2 sign = O");
    printf("\n\tTo exit from game, Enter -1\n");
 
    printf("\n\n* Cell Numbers on Board\n");
    initializeBoard();
 
    char start = ' ';
    printf("\n> Press Enter to start...");
 
    scanf("%c", &start);
 
    if (start)
    {
        int userChoice = 1;
        // restart the game
        while (userChoice)
        {
            playTicTacToe();
            printf("\n* Menu\n");
            printf("\nPress 1 to Restart");
            printf("\nPress 0 for Exit");
            printf("\n\nChoice: ");
            scanf("%d", &userChoice);
            if (userChoice)
            {
                initializeBoard();
            }
            printf("\n");
        }
    }
    printf("\n :: Thanks for playing Tic Tac Toe game! :: \n");
}

// Tictactoe ends here















// Rock Paper Scissor starts here

int RockPaperScissor() {
    int playerChoice, computerChoice;
    int playerScore = 0, computerScore = 0;
    int rounds, currentRound = 0;

    printf("Welcome to Rock, Paper, Scissors!\n");
    printf("Enter the number of rounds: ");
    scanf("%d", &rounds);

    // Seed the random number generator
    srand(time(NULL));

    while (currentRound < rounds) {
        printf("\nRound %d\n", currentRound + 1);
        printf("1. Rock\n");
        printf("2. Paper\n");
        printf("3. Scissors\n");
        printf("Enter your choice (1/2/3): ");
        scanf("%d", &playerChoice);

        // Ensure the player's choice is valid
        if (playerChoice < 1 || playerChoice > 3) {
            printf("Invalid choice. Please enter 1, 2, or 3.\n");
            continue;
        }

        // Generate a random choice for the computer (1 = Rock, 2 = Paper, 3 = Scissors)
        computerChoice = rand() % 3 + 1;

        // Determine the winner of the round
        if (playerChoice == computerChoice) {
            printf("It's a tie!\n");
        } else if ((playerChoice == 1 && computerChoice == 3) ||
                   (playerChoice == 2 && computerChoice == 1) ||
                   (playerChoice == 3 && computerChoice == 2)) {
            printf("You win this round!\n");
            playerScore++;
        } else {
            printf("Computer wins this round!\n");
            computerScore++;
        }

        currentRound++;
    }

    printf("\nGame Over!\n");
    printf("Your Score: %d\n", playerScore);
    printf("Computer's Score: %d\n", computerScore);

    if (playerScore > computerScore) {
        printf("Congratulations, you win the game!\n");
    } else if (computerScore > playerScore) {
        printf("Computer wins the game. Better luck next time!\n");
    } else {
        printf("It's a tie game!\n");
    }

    return 0;
}
// Rock Paper Scissor ends here






// code for snake

int length;
int bend_no;
int len;
char key;
void record();
void load();
int life;
void Delay(long double);
void Move();
void Food();
int Score();
void Print();
void gotoxy(int x, int y);
void GotoXY(int x,int y);
void Bend();
void Boarder();
void Down();
void Left();
void Up();
void Right();
void ExitGame();
int Scoreonly();

struct coordinate
{
    int x;
    int y;
    int direction;
};

typedef  struct coordinate coordinate;

coordinate head, bend[500],food,body[30];

int snake()
{

    char key;

    Print();

    system("cls");

    load();

    length=5;

    head.x=25;

    head.y=20;

    head.direction=RIGHT;

    Boarder();

    Food(); //to generate food coordinates initially

    life=3; //number of extra lives

    bend[0]=head;

    Move();   //initialing initial bend coordinate

    return 0;

}

void Move()
{
    int a,i;

    do
    {

        Food();
        fflush(stdin);

        len=0;

        for(i=0; i<30; i++)

        {

            body[i].x=0;

            body[i].y=0;

            if(i==length)

                break;

        }

        Delay(length);

        Boarder();

        if(head.direction==RIGHT)

            Right();

        else if(head.direction==LEFT)

            Left();

        else if(head.direction==DOWN)

            Down();

        else if(head.direction==UP)

            Up();

        ExitGame();

    }
    while(!kbhit());

    a=getch();

    if(a==27)

    {

        system("cls");

        exit(0);

    }
    key=getch();

    if((key==RIGHT&&head.direction!=LEFT&&head.direction!=RIGHT)||(key==LEFT&&head.direction!=RIGHT&&head.direction!=LEFT)||(key==UP&&head.direction!=DOWN&&head.direction!=UP)||(key==DOWN&&head.direction!=UP&&head.direction!=DOWN))

    {

        bend_no++;

        bend[bend_no]=head;

        head.direction=key;

        if(key==UP)

            head.y--;

        if(key==DOWN)

            head.y++;

        if(key==RIGHT)

            head.x++;

        if(key==LEFT)

            head.x--;

        Move();

    }

    else if(key==27)

    {

        system("cls");

        exit(0);

    }

    else

    {

        printf("\a");

        Move();

    }
}

void gotoxy(int x, int y)
{

    COORD coord;

    coord.X = x;

    coord.Y = y;

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

}
void GotoXY(int x, int y)
{
    HANDLE a;
    COORD b;
    fflush(stdout);
    b.X = x;
    b.Y = y;
    a = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(a,b);
}
void load()
{
    int row,col,r,c,q;
    gotoxy(36,14);
    printf("loading...");
    gotoxy(30,15);
    for(r=1; r<=20; r++)
    {
        for(q=0; q<=100000000; q++); //to display the character slowly
        printf("%c",177);
    }
    getch();
}
void Down()
{
    int i;
    for(i=0; i<=(head.y-bend[bend_no].y)&&len<length; i++)
    {
        GotoXY(head.x,head.y-i);
        {
            if(len==0)
                printf("v");
            else
                printf("*");
        }
        body[len].x=head.x;
        body[len].y=head.y-i;
        len++;
    }
    Bend();
    if(!kbhit())
        head.y++;
}
void Delay(long double k)
{
    Score();
    long double i;
    for(i=0; i<=(10000000); i++);
}
void ExitGame()
{
    int i,check=0;
    for(i=4; i<length; i++) //starts with 4 because it needs minimum 4 element to touch its own body
    {
        if(body[0].x==body[i].x&&body[0].y==body[i].y)
        {
            check++;    //check's value increases as the coordinates of head is equal to any other body coordinate
        }
        if(i==length||check!=0)
            break;
    }
    if(head.x<=10||head.x>=70||head.y<=10||head.y>=30||check!=0)
    {
        life--;
        if(life>=0)
        {
            head.x=25;
            head.y=20;
            bend_no=0;
            head.direction=RIGHT;
            Move();
        }
        else
        {
            system("cls");
            printf("All lives completed\nBetter Luck Next Time!!!\nPress any key to quit the game\n");
            record();
            exit(0);
        }
    }
}
void Food()
{
    if(head.x==food.x&&head.y==food.y)
    {
        length++;
        time_t a;
        a=time(0);
        srand(a);
        food.x=rand()%70;
        if(food.x<=10)
            food.x+=11;
        food.y=rand()%30;
        if(food.y<=10)

            food.y+=11;
    }
    else if(food.x==0)/*to create food for the first time coz global variable are initialized with 0*/
    {
        food.x=rand()%70;
        if(food.x<=10)
            food.x+=11;
        food.y=rand()%30;
        if(food.y<=10)
            food.y+=11;
    }
}
void Left()
{
    int i;
    for(i=0; i<=(bend[bend_no].x-head.x)&&len<length; i++)
    {
        GotoXY((head.x+i),head.y);
        {
            if(len==0)
                printf("<");
            else
                printf("*");
        }
        body[len].x=head.x+i;
        body[len].y=head.y;
        len++;
    }
    Bend();
    if(!kbhit())
        head.x--;

}
void Right()
{
    int i;
    for(i=0; i<=(head.x-bend[bend_no].x)&&len<length; i++)
    {
        //GotoXY((head.x-i),head.y);
        body[len].x=head.x-i;
        body[len].y=head.y;
        GotoXY(body[len].x,body[len].y);
        {
            if(len==0)
                printf(">");
            else
                printf("*");
        }
        /*body[len].x=head.x-i;
        body[len].y=head.y;*/
        len++;
    }
    Bend();
    if(!kbhit())
        head.x++;
}
void Bend()
{
    int i,j,diff;
    for(i=bend_no; i>=0&&len<length; i--)
    {
        if(bend[i].x==bend[i-1].x)
        {
            diff=bend[i].y-bend[i-1].y;
            if(diff<0)
                for(j=1; j<=(-diff); j++)
                {
                    body[len].x=bend[i].x;
                    body[len].y=bend[i].y+j;
                    GotoXY(body[len].x,body[len].y);
                    printf("*");
                    len++;
                    if(len==length)
                        break;
                }
            else if(diff>0)
                for(j=1; j<=diff; j++)
                {
                    /*GotoXY(bend[i].x,(bend[i].y-j));
                    printf("*");*/
                    body[len].x=bend[i].x;
                    body[len].y=bend[i].y-j;
                    GotoXY(body[len].x,body[len].y);
                    printf("*");
                    len++;
                    if(len==length)
                        break;
                }
        }
        else if(bend[i].y==bend[i-1].y)
        {
            diff=bend[i].x-bend[i-1].x;
            if(diff<0)
                for(j=1; j<=(-diff)&&len<length; j++)
                {
                    /*GotoXY((bend[i].x+j),bend[i].y);
                    printf("*");*/
                    body[len].x=bend[i].x+j;
                    body[len].y=bend[i].y;
                    GotoXY(body[len].x,body[len].y);
                    printf("*");
                    len++;
                    if(len==length)
                        break;
                }
            else if(diff>0)
                for(j=1; j<=diff&&len<length; j++)
                {
                    /*GotoXY((bend[i].x-j),bend[i].y);
                    printf("*");*/
                    body[len].x=bend[i].x-j;
                    body[len].y=bend[i].y;
                    GotoXY(body[len].x,body[len].y);
                    printf("*");
                    len++;
                    if(len==length)
                        break;
                }
        }
    }
}
void Boarder()
{
    system("cls");
    int i;
    GotoXY(food.x,food.y);   /*displaying food*/
    printf("F");
    for(i=10; i<71; i++)
    {
        GotoXY(i,10);
        printf("!");
        GotoXY(i,30);
        printf("!");
    }
    for(i=10; i<31; i++)
    {
        GotoXY(10,i);
        printf("!");
        GotoXY(70,i);
        printf("!");
    }
}
void Print()
{
    //GotoXY(10,12);
    printf("\tWelcome to the mini Snake game.(press any key to continue)\n");
    getch();
    system("cls");
    printf("\tGame instructions:\n");
    printf("\n-> Use arrow keys to move the snake.\n\n-> You will be provided foods at the several coordinates of the screen which you have to eat. Everytime you eat a food the length of the snake will be increased by 1 element and thus the score.\n\n-> Here you are provided with three lives. Your life will decrease as you hit the wall or snake's body.\n\n-> YOu can pause the game in its middle by pressing any key. To continue the paused game press any other key once again\n\n-> If you want to exit press esc. \n");
    printf("\n\nPress any key to play game...");
    if(getch()==27)
        exit(0);
}
void record()
{
    char plname[20],nplname[20],cha,c;
    int i,j,px;
    FILE *info;
    info=fopen("record.txt","a+");
    getch();
    system("cls");
    printf("Enter your name\n");
    scanf("%[^\n]",plname);
    //************************
    for(j=0; plname[j]!='\0'; j++) //to convert the first letter after space to capital
    {
        nplname[0]=toupper(plname[0]);
        if(plname[j-1]==' ')
        {
            nplname[j]=toupper(plname[j]);
            nplname[j-1]=plname[j-1];
        }
        else nplname[j]=plname[j];
    }
    nplname[j]='\0';
    //*****************************
    //sdfprintf(info,"\t\t\tPlayers List\n");
    fprintf(info,"Player Name :%s\n",nplname);
    //for date and time

    time_t mytime;
    mytime = time(NULL);
    fprintf(info,"Played Date:%s",ctime(&mytime));
    //**************************
    fprintf(info,"Score:%d\n",px=Scoreonly());//call score to display score
    //fprintf(info,"\nLevel:%d\n",10);//call level to display level
    for(i=0; i<=50; i++)
        fprintf(info,"%c",'_');
    fprintf(info,"\n");
    fclose(info);
    printf("Wanna see past records press 'y'\n");
    cha=getch();
    system("cls");
    if(cha=='y')
    {
        info=fopen("record.txt","r");
        do
        {
            putchar(c=getc(info));
        }
        while(c!=EOF);
    }
    fclose(info);
}
int Score()
{
    int score;
    GotoXY(20,8);
    score=length-5;
    printf("SCORE : %d",(length-5));
    score=length-5;
    GotoXY(50,8);
    printf("Life : %d",life);
    return score;
}
int Scoreonly()
{
    int score=Score();
    system("cls");
    return score;
}
void Up()
{
    int i;
    for(i=0; i<=(bend[bend_no].y-head.y)&&len<length; i++)
    {
        GotoXY(head.x,head.y+i);
        {
            if(len==0)
                printf("^");
            else
                printf("*");
        }
        body[len].x=head.x;
        body[len].y=head.y+i;
        len++;
    }
    Bend();
    if(!kbhit())
        head.y--;
}

// code for snake ends here









int main()
{
    while(1){
    int a1;
    printf("*_______Welcome To Arcade Mania________*\n\t1.Tictactoe\n\t2.Fruit Wordle\n\t3.Rock Paper Scissor\n\t4.Snake game\n\t5.Exit\nEnter your choice: ");
    scanf("%d", &a1);

    switch(a1){
        case 1: 
        tictac();
        break;
        case 2: 
        wordle();
        break;
        case 3:
        RockPaperScissor();
        break;
        case 4:
        snake();
        break;
        case 5:
        exit(0);
        default:
        printf("Invalid input.\n");
        break;
    }
    }

    return 0;
    
}

