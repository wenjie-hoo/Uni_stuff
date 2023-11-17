package games
import cards._
import deck._

class Blackjack(deck: Deck) {
  private var playerCards: List[Card] = List.empty[Card]
  private var dealerCards: List[Card] = List.empty[Card]

  private def calculatePoints(cards: List[Card]): Int = {
    def helper(cards: List[Card], points: Int, numOfAces: Int): Int = cards match {

  }

  private def printCards(cards: List[Card]): Unit = {
    cards.foreach(card => println(s"${card.value} of ${card.value} - ${card.value} points"))
  }

  def play(n: Int): Unit = {

  }

  def first21(): Unit = {

}

object Blackjack {
  def apply(numOfDecks: Int): Blackjack = {
    val deck = Deck(List.fill(numOfDecks)(Deck.isStandard).flatten)
    new Blackjack(Random.shuffle(deck.cards))
  }
}

