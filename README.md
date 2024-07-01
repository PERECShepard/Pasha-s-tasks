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

*/

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
