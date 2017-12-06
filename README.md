# Movie Ratings System
A program that allows a user to enter ratings for three out of six movies, and then predicts the user's ratings for the
remaining three movies.

### Synopsis
Four reviewers numbered 0-3 have rated six movies where the movies are numbered 100-105. 

The ratings range from 1 (terrible) to 5 (excellent).

The reviews are shown in the following table:

|    |  100 | 101 | 102 | 103 | 104 | 105 |
|----|:----:|----:|----:|----:|----:|----:|
|  0 |   3  |  1  |  5  |  2  |  1  |  5  |
|  1 |   4  |  2  |  1  |  4  |  2  |  4  |
|  2 |   3  |  1  |  2  |  4  |  4  |  1  |
|  3 |   5  |  1  |  4  |  2  |  4  |  2  |

Based on this information, the program will allow a user to enter ratings for any three movies.

The program should then predict a user's interest for the remaining three movies by outputting<br />
the ratings by the reviewer for the movies that were not rated by the user.

## Setup
1. Download and install [Git](https://git-scm.com/downloads), if you don't already have it.

2. Open terminal and run the git clone command:

   ```
   $ git clone https://github.com/cramaechi/movie-ratings-system.git
   ```
    or [download as ZIP](https://github.com/cramaechi/movie-ratings-system/archive/master.zip).

3. Go to the project folder:

   ```
   $ cd divers-score
   ```

4. Compile:

   ```
   $ make
   ```
   
## Usage
Run:

```
$ ./divers_score
```
Sample Output:
```
Select movie: 102                                                                                                     
                                                                                                                      
Enter rating: 5                                                                                                       
                                                                                                                      
Select movie: 104                                                                                                     
                                                                                                                      
Enter rating: 2                                                                                                       
                                                                                                                      
Select movie: 105                                                                                                     
                                                                                                                      
Enter rating: 5                                                                                                       
                                                                                                                      
The reviewer who's ratings most closely matches your ratings is reviewer 0.                                           
                                                                                                                      
This program has predicted your ratings for the remaining three movies:                                               
                                                                                                                      
Movie 100 rating: 3                                                                                                   
Movie 101 rating: 1                                                                                                   
Movie 103 rating: 2 
```
