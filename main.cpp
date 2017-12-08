//Program that prompts the user to rate any 3 of 6 movies (1-5 rating range),
//finds the movie reviewer with the closest ratings to the users input, and 
//predicts the user's ratings for the remaining three movies.
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>

using namespace std;

const int ROW = 4;
const int COLUMN = 6;

void userInput(int userRatings[]);
//Precondition: arraySize >= 0 && <= 5. numberUsed >= 0 && <= arraySize.
//Postcondition: All or almost all elements of ratings have been initialized.
//The value of numberUsed has been set.

void findReviewerMatch(int reviewerRatings[][COLUMN], int userRatings[], int& reviewer);
//Precondition: Both arrays reviewerRatings and userRatings have been almost or
//entirely filled. arraySize >= 0 && <= 6.
//Postcondition: The value of variable reviewer has been set.

void predictLastThreeMovieRatings(int reviewerRatings[][COLUMN], int userRatings[], int reviewer, int lastThreeRatings[]);
//Precondition: Both arrays reviewerRatings and userRatings have been entirely
//or almost filled. reviewer >= 0 && <= 3.
//Postcondition: The values of ratings1, ratings2, and ratings3 have all been
//initialized.

void displayResults(int lastThreeRatings[], int reviewer, int size);
//Precondition: The array lastThreeRatings has been partially filled.
//reviewer >= 0 && <= 3. size == 6.
//Postcondition: Displays the reviewer with the closest movie ratings to the 
//user's ratings input and predicts the user's ratings for the remaining three
//movies.

int main()
{
    int reviewerRatings[ROW][COLUMN] = {3,1,5,2,1,5,4,2,1,4,2,4,3,1,2,4,4,1,5,1,4,2,4,2};
    int userRatings[COLUMN] = {0}, lastThreeMovies[COLUMN] = {0}, closestReviewer;

    userInput(userRatings);
    findReviewerMatch(reviewerRatings, userRatings, closestReviewer);
    predictLastThreeMovieRatings(reviewerRatings, userRatings, closestReviewer, lastThreeMovies);
    displayResults(lastThreeMovies, closestReviewer, COLUMN);

    return 0;
}

void userInput(int userRatings[])
{
    int m, r;

    for (int i = 0; i < 3; i++)
    {
        cout<<"Select movie: ";
        cin>>m;
        cout<<"\nEnter rating: ";
        cin>>r;
        cout<<endl;
        userRatings[m % 10] = r;
    }
}

void findReviewerMatch(int reviewerRatings[][COLUMN], int userRatings[], int& reviewer)
{
    int minDistance = INT_MAX;
    double reviewerDistance = 0;

    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COLUMN; j++)
        {
            if (userRatings[j] >= 1)
                reviewerDistance+=pow(userRatings[j]-reviewerRatings[i][j], 2.0);
        }

        if (reviewerDistance < minDistance)
        {
            minDistance = reviewerDistance;
            reviewer = i;
        }

        reviewerDistance = 0;
    }
}

void predictLastThreeMovieRatings(int reviewerRatings[][COLUMN], int userRatings[], int reviewer, int lastThreeRatings[])
{
    int index = 0;

    for (int i = reviewer; i <= reviewer; i++)
    {
        for (int j = 0; j < COLUMN; j++)
        {
            if (userRatings[j] == 0)
                lastThreeRatings[j] = reviewerRatings[i][j];
        }
    }
}

void displayResults(int lastThreeRatings[], int reviewer, int size)
{
    cout<<"The reviewer who's ratings most closely matches your ratings is reviewer "<<reviewer<<".\n\n";
    cout<<"This program has predicted your ratings for the remaining three movies:\n\n";

    for (int i = 0; i < size; i++)
    {
        if (lastThreeRatings[i] >= 1)
            cout<<"Movie "<<100+i<<" rating: "<<lastThreeRatings[i]<<endl;
    }

    cout<<endl;
}
