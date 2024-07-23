/*Task002: Multiply numbers

Player in start game enter two number instead of one number.
Computer choose two number instread of one number.

Earch one does not choose equesls numbers 
incorrect: 
2 2 
0 0 
10 10
correct: 
1 2
5 7
8 2

The game is playing before each has more than 100 in balance

The random service can make number in range of 1 to 20 includes


Imagine a game that simulates a simple card selection process:

You visit a friend's house, and he pulls out 10 cards from a deck; you can't see what these cards are. You choose, for example, the 4th and 5th cards, which turn out to be a "10" and a "King."

Then your friend (the robot) also selects 10 new cards from the deck and chooses the 2nd and 8th cards. He gets a "6" and a "Jack."

Next, a random number generator picks a number from 1 to 20, and the sum of the cards that is closest to this number wins. It could also result in a tie.

What needs to be implemented:

A service for generating an array of cards based on real conditions from a 52-card deck (no jokers), where the cards should be in a random order.
A service for counting the cards. For example, if I have a King and a 10, that's 14 points (ace = 11).
A function where I pass the card value, and it translates it into a number.
The program should look like this:

<Game start>
You play
Choose your card:
[#][#][#][#][#][#][#][#][#][#]
3
[#][#][K][#][#][#][#][#][#][#]
Choose your another card:
10
[#][#][K][#][#][#][#][#][#][A]
Your cards:
[K][10]
Computer play
[#][#][#][#][#][#][#][#][#][#]
Computer chooses: 2
[#][6][#][#][#][#][#][#][#][#]
Computer chooses: 8
[#][6][#][#][#][#][#][#][A][#]
Computer cards:
[6][A]

Random number chosen: 18
You have [K][A] = 15
Computer has [6][A] = 17

Computer wins \$100
Your balance: \$900, computer: \$1100.
New round:
You play
Choose your card:
[#][#][#][#][#][#][#][#][#][#]
...
*/

Task 004: Let's Move Forward:

Now we're playing Blackjack. Our rules are simple:
If you have 21, you win.
If you have more than 21, you definitely lose.
If you and the computer both have 21, you both win.
If you and the computer both have more than 21, it's a draw - no one wins or loses money.
If you have two Aces, you win immediately, and the computer doesn't play.
If you and the computer both have less than 21, the one who is closer to 21 wins.
When the user has chosen 2 cards, the program asks if they want to open another card. If they respond "Yes", they see 3 cards, and the program asks again if they want to open another card. If they respond "No", the program continues. The user can open up to 10 cards.
After the user has opened 2 cards, the computer, if its value is less than 21, uses statistics and probability theory to decide whether to open another card, based on the cards the user has opened and the remaining cards on the table and in the deck. If it decides to open another card, it does so and makes another decision, either to continue playing or to open another card. This continues up to 10 cards.
After each card is opened, the points should be displayed next to the cards.
Example of the game, with proper indentation:

Your balance: 1000 | Computer's balance: 1000

You play Choose your card: [#][#][#][#][#][#][#][#][#][#] | 0 points 
3 // my input

[#][#][K][#][#][#][#][#][#][#] | 4 points Choose your another card: 
10 // my input

[#][#][K][#][#][#][#][#][#][8] | 12 points Do you want to open another card? Yes/No (addition 1.1) yes 
// ignoring case

[#][#][K][#][#][#][#][#][#][8] | 12 points Choose your another card: 7

[#][#][K][#][#][#][A][#][#][8] | 23 points Do you want to open another card? Yes/No (addition 1.1) no 
// ignoring case

Your cards: [K][A][8] | 23 points

[#][#][K][#][#][#][#][#][#][A]

Computer play: [#][#][#][#][#][#][#][#][#][#] | 0 points 
Computer chooses: 2 [#][6][#][#][#][#][#][#][#][#] | 6 points 
Computer chooses: 8 [#][6][#][#][#][#][#][#][A][#] | 17 points 
Computer chooses: 1 [K][6][#][#][#][#][#][#][A][#] | 21 points 
Computer cards: [K][6][A] | 21 points

You have [K][A][8] | 23 points 
Computer has [K][6][A] | 21 points Computer WIN

Your balance: 900 | Computer's balance: 1100

....

Addition 1.1: // (If nothing is entered (just pressing Enter), the game continues as if nothing was chosen) 
// (If 'No' is entered, the game continues as if nothing was chosen) 
// (If 'Yes' is entered, the cards are shown and "Choose your another card:" is displayed) 
// (If a card that is already opened is entered, "This card is already open" is displayed, and the cards are shown again with "Choose your another card:")
