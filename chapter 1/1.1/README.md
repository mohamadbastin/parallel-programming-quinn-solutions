## Question 1.1:

Try these experiments with a few friends.
a. Shuffle a deck of cards, then determine how long it takes one person
to sort the cards into the order A spades, 2 spades,..., K spades, A hearts, 2 hearts,..., K hearts,
A clubs, 2 clubs,..., K clubs, ..., A diamonds, 2 diamonds,..., K diamonds.

b. How long does it take p people to sort p decks of shuffled cards?

c. How long does it take p people to sort one deck of cards? Try this
experiment for p = 1, 2, ..., 6. How does your algorithm change as
p changes?

--------------

a. so my take is that if putting one card in its right place takes 1 unit of time, then a deck of 
cards which we will assume consists of 52 cards, takes 52 units of time to be ordered by one person.

b. if we have P decks then we have 52*P cards. but here we can order P cards simultaneously 
because we have P people. so basically it takes (52*P)/P = 52 units of time to sort P decks of cards 
by P people.

c. so logically it should take 52/P units of time. but as this is a experimental question and I'm 
just answering theoretically, it probably wouldn't be this straightforward. as P increases, people 
would probably get in the way of each other, so probably new algorithms would be suggested.