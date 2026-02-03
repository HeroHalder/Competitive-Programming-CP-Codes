
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h> // For random toss

#define MAX_PLAYERS 11


int striker_runs = 0, non_striker_runs = 0, striker_balls = 0, non_striker_balls = 0;
// Functon to reset the striker or non_striker balls_faced...



// First Function...

void initialize_scoreboard(char team1_players[MAX_PLAYERS][50], char team2_players[MAX_PLAYERS][50])
{
    char team1_name[50], team2_name[50];
    char team1_captain[50], team2_captain[50];
    int toss_result, batting_team;

    printf("Enter team 1 name: ");
    fgets(team1_name, sizeof(team1_name), stdin);
    team1_name[strcspn(team1_name, "\n")] = '\0';

    printf("Enter captain name for %s: ", team1_name);
    fgets(team1_captain, sizeof(team1_captain), stdin);
    team1_captain[strcspn(team1_captain, "\n")] = '\0';

    printf("Enter team 2 name: ");
    fgets(team2_name, sizeof(team2_name), stdin);
    team2_name[strcspn(team2_name, "\n")] = '\0';

    printf("Enter captain name for %s: ", team2_name);
    fgets(team2_captain, sizeof(team2_captain), stdin);
    team2_captain[strcspn(team2_captain, "\n")] = '\0';

    printf("Enter player names for %s (maximum %d):\n", team1_name, MAX_PLAYERS);
    for (int i = 0; i < MAX_PLAYERS; i++)
    {
        printf("Player %d: ", i + 1);
        fgets(team1_players[i], sizeof(team1_players[i]), stdin);
        team1_players[i][strcspn(team1_players[i], "\n")] = '\0';
    }

    printf("Enter player names for %s (maximum %d):\n", team2_name, MAX_PLAYERS);
    for (int i = 0; i < MAX_PLAYERS; i++)
    {
        printf("Player %d: ", i + 1);
        fgets(team2_players[i], sizeof(team2_players[i]), stdin);
        team2_players[i][strcspn(team2_players[i], "\n")] = '\0';
    }

    printf(R"EOF(
     _____                       _____   _
    |_   _|   ___    ___   ___  |_   _| (_)  _ __ ___     ___
      | |    / _ \  / __| / __|   | |   | | | '_ ` _ \   / _ \
      | |   | (_) | \__ \ \__ \   | |   | | | | | | | | |  __/
      |_|    \___/  |___/ |___/   |_|   |_| |_| |_| |_|  \___|)EOF");
    printf("\n");
    printf("\n");

    srand(time(NULL));
    toss_result = rand() % 2;
    batting_team = toss_result;

    printf("Toss result: %s won the toss and elected to %s\n", (toss_result == 0) ? team1_name : team2_name, (rand() % 2 == 0) ? "bat" : "bowl");

    display_initial_scoreboard(team1_name, team2_name, batting_team, 0, 0, 0, 0.0, (batting_team == 0) ? team1_players : team2_players, (int[2])
    {
        0, 1
    });
}
// Display initial scoreboard
void display_initial_scoreboard(char team1_name[], char team2_name[], int batting_team, int runs, int wickets, int overs, float run_rate, char player_names[MAX_PLAYERS][50], int current_batsman[2])
{
    printf(R"EOF(
     ___                     _
    |_ _|_ __ (_) |_(_) __ _| |
     | || '_ \| | __| |/ _` | |
     | || | | | | |_| | (_| | |
    |___|_| |_|_|\__|_|\__,_|_|
      ___                     _
    / ___|  ___ ___  _ __ ___| |__   ___   __ _ _ __ __| |
    \___ \ / __/ _ \| '__/ _ \ '_ \ / _ \ / _` | '__/ _` |
     ___) | (_| (_) | | |  __/ |_) | (_) | (_| | | | (_| |
    |____/ \___\___/|_|  \___|_.__/ \___/ \__,_|_|  \__,_|)EOF");
    printf("\n");
    printf("\n");
    printf("--------------------------------------------------------------------------\n");
    printf("Welcome to the game between %s and %s!\n", team1_name, team2_name);
    printf("--------------------------------------------------------------------------\n");
    printf("Team batting: %s\n", (batting_team == 0) ? team1_name : team2_name);
    printf("Runs: %d\n", runs);
    printf("Wickets: %d\n", wickets);
    printf("Overs: %d.%d\n", overs / 6, overs % 6);
    printf("Run Rate: %.2f\n", run_rate);
    printf("Current Batsmen:\n");
    printf("- %s (Striker)\n", player_names[current_batsman[0]]);
    printf("- %s (Non-Striker)\n", player_names[current_batsman[1]]);
    printf("--------------------------------------------------------------------------\n");
    printf(R"EOF(
    --------------------------------------------------------------------------

    @                                _                                  ,,
     \\   _   @'                    ( )_                       .      _  \\
      \\_( )_//                    / Y |                   .      /--( )_//
        | Y/--                    /\   /               .        '//  \~ \
        |_/       _ / o"         ( _\ /            .                   - \
      _ //\      | | |    .       \_\\\        .                     //  \\--,
     /_// /      | | |      .    / \ \\\ .                           \\
    / // /_______|_|_|__________/_/_\ \_______________________________\\______
    -------------------------------------------- Let's Play ----------------)EOF");
    printf("\n");
}

// Function to display all the player's name...
void display_players_name(char team_players[MAX_PLAYERS][50], int num_players)
{
    printf("Player names:\n");
    for (int i = 0; i < num_players; i++)
    {
        printf("%d. %s\n", i + 1, team_players[i]);
    }
}

// Third Function...!!!
void record_wickets(int over, int ball, int striker_runs, int non_striker_runs, int striker_balls, int non_striker_balls)
{
    char wicket_type[20], bowler_name[20], faced4[10], option;
    fflush(stdin);
    printf("Is the batsman got out at 0? Type'y' for 'yes!' or Type 'n' for 'no!': ");
    scanf("%c", &option);
    if (option == 'y')
    {
        printf(R"EOF(
                              ____    ___    _       ____    _____   _   _
                             / ___|  / _ \  | |     |  _ \  | ____| | \ | |
                            | |  _  | | | | | |     | | | | |  _|   |  \| |
                            | |_| | | |_| | | |___  | |_| | | |___  | |\  |
                             \____|  \___/  |_____| |____/  |_____| |_| \_|
                            |  _ \  | | | |  / ___| | |/ / | | | |
                            | | | | | | | | | |     | ' /  | | | |
                            | |_| | | |_| | | |___  | . \  |_|_|_|
                            |____/   \___/   \____| |_|\_\ (_|_|_) )EOF");
        printf("\n");
    }

    fflush(stdin);
    printf("How did the wicket fall? ");
    scanf("%s", &wicket_type);

    fflush(stdin);
    printf("Who took the wicket? ");
    scanf("%s", &bowler_name);

    printf("The wicket has been taken by %s at ball %d of over %d by %s out\n", bowler_name, ball, over, wicket_type);

    fflush(stdin);
    printf("Who faced the ball? 'striker' or 'non_striker'? ");
    scanf("%s", &faced4);

    if (strcmp(faced4, "striker") == 0)
    {
        striker_balls += 1;
        printf("%d ball(s) faced by %s\n", striker_balls, faced4);
        printf("%s out at %d run and faced %d ball(s)\n", faced4, striker_runs, striker_balls);
    }
    if (strcmp(faced4, "non_striker") == 0)
    {
        non_striker_balls += 1;
        printf("%d ball(s) faced by the %s\n", non_striker_balls, faced4);
        printf("%s out at %d run and faced %d balls\n", faced4, striker_runs, striker_balls);
    }
    update_batsmen();
}
// Fourth Function...!!!
void update_batsmen()
{
    char new_batsman_name[20], ch;
    printf("New Batsman name? ");
    scanf("%s", new_batsman_name);
    // printf("%s",new_batsman_name);
    printf("Is the new batsman 'striker' or 'non_striker'? Type 's' for 'striker' or Type 'n' for 'non_striker': ");
    scanf(" %c", &ch); // Added space before %c

    if (ch == 's')
    {
        setNameStriker(new_batsman_name);
    }
    else
    {
        setNameNonStriker(new_batsman_name);
    }
}

// Fourth Function 1.0..
void setNameStriker(char name[])
{
    char ch[20];
    printf("New striker batsman name? ");
    scanf("%s", ch);
    printf("%s\n", ch);

    if (strcmp(name, ch) == 0)
    {
        striker_balls = 0;
        striker_runs = 0;
    }
}

// Fourt Function 1.1...
void setNameNonStriker(char name[])
{
    char ch[20];
    printf("New non_striker batsman name? ");
    scanf("%s", ch);
    printf("%s\n", ch);

    if (strcmp(name, ch) == 0)
    {
        non_striker_balls = 0;
        non_striker_runs = 0;
    }
}

// Eighth Function...
void display_scoreboard(int total_runs, int balls_faced, int wickets_fallen)
{

    printf(R"EOF(
     ____                     _                         _
    / ___|  ___ ___  _ __ ___| |__   ___   __ _ _ __ __| |
    \___ \ / __/ _ \| '__/ _ \ '_ \ / _ \ / _` | '__/ _` |
     ___) | (_| (_) | | |  __/ |_) | (_) | (_| | | | (_| |
    |____/ \___\___/|_|  \___|_.__/ \___/ \__,_|_|  \__,_|
     _____ _____ _____ _____ _____ _____ _____ _____ _____ _____ _____ _____
    |_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|)EOF");
    printf("\n");
    printf("--------------------------------------------------------------------------\n");
    printf("Total Runs: %d\n", total_runs);
    printf("Total Balls in this over: %d\n", balls_faced);
    printf("Wickets Fallen: %d\n", wickets_fallen);
    printf("--------------------------------------------------------------------------\n");
}
// Seventh Function...
float calculate_run_rate(int total_runs, int overs_till_bowled)
{
    return (float)total_runs / overs_till_bowled;
}

// Second Function....
void record_runs()
{

    int total_runs = 0;
    int falls_of_wicket = 0;
    char bowler_name[20];
    int desired_over;
    int overs_bowled = 0;

    printf("How many overs to be played? ");
    scanf("%d", &desired_over);
    for (int over = 1; over <= desired_over; over++)
    {

        int ball_faced = 0;
        printf("--------------------------------------\n----------------------------------------------\n");
        fflush(stdin);
        printf("Current Bowler Name: ");
        scanf("%s", &bowler_name);

        printf("Current Over: %d\n", over);
        printf("--------------------------------------\n----------------------------------------------\n");


        int current_bowler_runs = 0;
        int current_bowler_wicket = 0;
        for (int ball = 1; ball <= 6; ball++)
        {
            printf("----------------------------------------------\n");
            printf("Select option given below...\n");
            printf("1. Batsman Run\n2. Byes Runs\n3. Leg Byes Runs\n4. Wicket\n5. Unable to Hit\n");
            printf("--------------------------------------\n----------------------------------------------\n");

            int choice;
            fflush(stdin);
            printf("Which option...? ");
            scanf("%d", &choice);

            switch (choice)
            {
            case 1:
                {
                    int score;
                    char no_ball;
                    char name[20];
                    fflush(stdin);
                    printf("Enter runs scored: ");
                    scanf("%d", &score);

                    if (score == 6)
                    {
                        printf(R"EOF(
                     ____    ___  __  __
                    / ___|  |_ _| \ \/ / __/\__
                    \___ \   | |   \  /  \    /
                     ___) |  | |   /  \  /_  _\
                    |____/  |___| /_/\_\   \/  )EOF");
                        printf("\n");
                    }

                    if (score == 4)
                    {
                        printf(R"EOF(
                     _____    ___    _   _   ____    _
                    |  ___|  / _ \  | | | | |  _ \  | |
                    | |_    | | | | | | | | | |_) | | |
                    |  _|   | |_| | | |_| | |  _ <  |_|
                    |_|      \___/   \___/  |_| \_\ (_))EOF");
                        printf("\n");
                    }
                    fflush(stdin);
                    printf("Runs scored by 'striker' or 'non_striker'?: ");
                    scanf("%s", &name);

                    if (strcasecmp(name, "striker") == 0)
                    {
                        striker_runs += score;
                        striker_balls += 1;
                        printf("Striker runs: %d\n", striker_runs);
                        printf("%d ball(s) faced by the striker\n", striker_balls);
                    }
                    else if (strcmp(name, "non_striker") == 0)
                    {
                        non_striker_runs += score;
                        non_striker_balls += 1;
                        printf("Non-Striker runs: %d\n", non_striker_runs);
                        printf("%d ball(s) faced by the non_striker\n", non_striker_balls);
                    }
                    else
                    {
                        printf("Invalid input!\n");
                    }

                    fflush(stdin);
                    printf("NO_BALL? Type 'y' for 'yes!' or Type 'n' for 'no!': ");
                    scanf(" %c", &no_ball);

                    if (no_ball == 'y')
                    {
                        total_runs += score;
                        total_runs += 1;
                        current_bowler_runs += score;
                        current_bowler_runs += 1;

                        printf(R"EOF(
                     _____   ____    _____   _____      _   _   ___   _____   _
                    |  ___| |  _ \  | ____| | ____|    | | | | |_ _| |_   _| | |
                    | |_    | |_) | |  _|   |  _|      | |_| |  | |    | |   | |
                    |  _|   |  _ <  | |___  | |___     |  _  |  | |    | |   |_|
                    |_|     |_| \_\ |_____| |_____|    |_| |_| |___|   |_|   (_))EOF");

                        printf("\n");
                        ball_faced++;
                    }
                    if (no_ball == 'n')
                    {
                        total_runs += score;
                        current_bowler_runs += score;

                        ball_faced++;
                    }
                    break;
                }
            case 2:
                {
                    char wide_ball;
                    int score1;
                    fflush(stdin);
                    printf("WIDE_BALL? Type 'y' for 'yes!' or Type 'n' for ;no!': ");
                    scanf("%c", &wide_ball);

                    if (wide_ball == 'y')
                    {
                        printf("WIDE...\n");
                        fflush(stdin);
                        printf("Enter runs scored including wide: ");
                        scanf("%d", &score1);
                        total_runs += score1;
                        current_bowler_runs += score1;
                        ball_faced++;
                    }
                    if (wide_ball == 'n')
                    {
                        fflush(stdin);
                        printf("Enter runs scored without wide: ");
                        scanf("%d", &score1);
                        total_runs += score1;
                        current_bowler_runs += score1;
                        ball_faced++;
                    }
                    break;
                }
            case 3:
                {
                    int score3;
                    char faced[10];
                    printf("Leg Byes...\n");
                    fflush(stdin);
                    printf("Enter runs scored by leg byes: ");
                    scanf("%d", &score3);
                    total_runs += score3;
                    ball_faced++;
                    fflush(stdin);
                    printf("Who faced the ball? 'striker' or 'non_striker'? ");
                    scanf("%s", &faced);

                    if (strcmp(faced, "striker") == 0)
                    {
                        striker_balls += 1;
                        printf("%d ball(s) faced by %s\n", striker_balls, faced);
                    }
                    else if (strcmp(faced, "non_striker") == 0)
                    {
                        non_striker_balls += 1;
                        printf("%d ball(s) faced by the %s\n", non_striker_balls, faced);
                    }
                    current_bowler_runs += score3;
                    break;
                }
            case 4:
                {
                    char valid_wicket;
                    int runs_in_this_ball;
                    fflush(stdin);
                    printf("Is it a valid wicket? Type 'y' for 'yes!' or Type 'n' for 'no!': ");
                    scanf("%c", &valid_wicket);

                    if (valid_wicket == 'y')
                    {

                        printf("Dismissal of a wicket...!\n");
                        printf(R"EOF(
                    __        __  ___    ____   _  __  _____   _____   _   _
                    \ \      / / |_ _|  / ___| | |/ / | ____| |_   _| | | | |
                     \ \ /\ / /   | |  | |     | ' /  |  _|     | |   | | | |
                      \ V  V /    | |  | |___  | . \  | |___    | |   |_| |_|
                       \_/\_/    |___|  \____| |_|\_\ |_____|   |_|   (_) (_))EOF");
                        printf("\n");

                        falls_of_wicket++;
                        record_wickets(over, ball, striker_runs, non_striker_runs, striker_balls, non_striker_balls);
                        ball_faced++;
                        current_bowler_wicket ++;


                        printf("Runs scored in this ball: ");
                        scanf("%d", &runs_in_this_ball);
                        current_bowler_runs += runs_in_this_ball;

                    }
                    else if (valid_wicket == 'n')
                    {
                        printf(R"EOF(
                     _   _  ___ _____    ___  _   _ _____
                    | \ | |/ _ \_   _|  / _ \| | | |_   _|
                    |  \| | | | || |   | | | | | | | | |
                    | |\  | |_| || |   | |_| | |_| | | |
                    |_| \_|\___/ |_|    \___/ \___/  |_|  )EOF");
                        printf("\n");
                        int score4;
                        fflush(stdin);
                        printf("Runs scored? Then how many runs? ");
                        scanf("%d", &score4);
                        total_runs += score4;
                        current_bowler_runs += score4;

                        ball_faced++;

                    }

                    break;
                }
            case 5:
                {
                    char faced5[10];
                    printf(R"EOF(
                  ___                          _
                 / _ \  ___   ___  _ __  ___  | |
                | | | |/ _ \ / _ \| '_ \/ __| | |
                | |_| | (_) | (_) | |_) \__ \ |_|
                 \___/ \___/ \___/| .__/|___/ (_)
                                  |_|
                             )EOF");
                    printf("\n");
                    ball_faced++;
                    fflush(stdin);
                    printf("Who faced the ball? 'striker' or 'non_striker'? ");
                    scanf("%s", &faced5);

                    if (strcmp(faced5, "striker") == 0)
                    {
                        striker_balls += 1;
                        printf("%d ball(s) faced by %s\n", striker_balls, faced5);
                    }
                    else if (strcmp(faced5, "non_striker") == 0)
                    {
                        non_striker_balls += 1;
                        printf("%d ball(s) faced by the %s\n", non_striker_balls, faced5);
                    }
                    break;
                }
            default:
                {
                    printf("Invalid Choice...!\n");
                }
            }
            display_scoreboard(total_runs, ball_faced, falls_of_wicket);


            if (ball_faced == 6)
            {
                printf(R"EOF(
                  ___                          _____               _
                 / _ \  __   __   ___   _ __  | ____|  _ __     __| |
                | | | | \ \ / /  / _ \ | '__| |  _|   | '_ \   / _` |
                | |_| |  \ V /  |  __/ | |    | |___  | | | | | (_| |
                 \___/    \_/    \___| |_|    |_____| |_| |_|  \__,_|)EOF");
                printf("\n");
                overs_bowled++;
                float run_rate = calculate_run_rate(total_runs, overs_bowled);
                printf("--------------------------------------------------------------------------\n");
                printf("Run Rate after Over %d: %.2f\n", over, run_rate);
                end_over(current_bowler_runs, current_bowler_wicket);
                printf("\n\n\n");
                printf("--------------------------------------------------------------------------\n");
                printf("--------------------------------------------------------------------------\n");
                printf(R"EOF(
                 _   _                      ___
                | \ | |   ___  __      __  / _ \  __   __   ___   _ __
                |  \| |  / _ \ \ \ /\ / / | | | | \ \ / /  / _ \ | '__|
                | |\  | |  __/  \ V  V /  | |_| |  \ V /  |  __/ | |
                |_| \_|  \___|   \_/\_/    \___/    \_/    \___| |_|)EOF");
                printf("\n");
                printf("\n\n\n\n");



            }
            else
            {

                printf(R"EOF(
                 _   _           _     ____        _ _   _
                | \ | | _____  _| |_  | __ )  __ _| | | | |
                |  \| |/ _ \ \/ / __| |  _ \ / _` | | | | |
                | |\  |  __/>  <| |_  | |_) | (_| | | | |_|
                |_| \_|\___/_/\_\\__| |____/ \__,_|_|_| (_))EOF");
                printf("\n");
            }
        }
        if (over == desired_over)
        {
            printf("\n\nEnd of the first half. After completing %d overs,\n", desired_over);
            printf(R"EOF(
             _____      _      ____     ____   _____   _____   _
            |_   _|    / \    |  _ \   / ___| | ____| |_   _| | |
              | |     / _ \   | |_) | | |  _  |  _|     | |   | |
              | |    / ___ \  |  _ <  | |_| | | |___    | |   |_|
              |_|   /_/   \_\ |_| \_\  \____| |_____|   |_|   (_))EOF");
            printf("\n");
            printf("\n");
            printf("The other team must be chased after %d runs\n", total_runs + 1);
        }
    }
}

void end_over(int runs, int wicket)
{
    printf("In this over:\n %d runs\n %d wicket(s)\n", runs, wicket);

}
int main()
{
    char team1_players[MAX_PLAYERS][50];
    char team2_players[MAX_PLAYERS][50];

    initialize_scoreboard(team1_players, team2_players);

    printf("\n");
    printf("Displaying player names for Team 1:\n");
    display_players_name(team1_players, MAX_PLAYERS);
    printf("\n");
    printf("Displaying player names for Team 2:\n");
    display_players_name(team2_players, MAX_PLAYERS);
    record_runs();

    return 0;
}
