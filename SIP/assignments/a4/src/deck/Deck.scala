package deck
import scala.util.Random
import cards._

class Deck(cards: List[Card]) {

  def pull(): Deck = new Deck(cards.tail)

  def push(c: Card): Deck = new Deck(c :: cards)
//  def push(suit: Suit, value: Value): Deck = new Deck(Card(suit, value) :: cards)

  val isStandard: Boolean = cards.length == 52 && amountOfColor(Clubs) == 13 && amountOfColor(Diamonds) == 13 &&
    amountOfColor(Hearts) == 13 && amountOfColor(Spades) == 13 && amountOfNumerical(Two) == 4 && amountOfNumerical(Three) == 4 &&
    amountOfNumerical(Four) == 4 && amountOfNumerical(Five) == 4 && amountOfNumerical(Six) == 4 && amountOfNumerical(Seven) == 4 &&
    amountOfNumerical(Eight) == 4 && amountOfNumerical(Nine) == 4 && amountOfNumerical(Ten) == 4 && amountOfFace(Jack) == 4 &&
    amountOfFace(Queen) == 4 && amountOfFace(King) == 4

  def duplicatesOfCard(card: Card): Int = cards.count(_ == card)

  def amountOfColor(color: Suit): Int = cards.count(_.suit == color)

  def amountOfNumerical(numerical: Value): Int = List(Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten).count(_ == numerical)

  val amountWithNumerical: Int = List(Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten).map(amountOfNumerical).sum

  def amountOfFace(face: Value): Int = List(Jack, Queen, King).count(_ == face)

  val amountWithFace: Int = List(Jack, Queen, King).map(amountOfFace).sum

}

object Deck {

  def apply(): Deck = new Deck(Random.shuffle(Deck.standardDeck))

  private def standardDeck: List[Card] = for {
    suit <- List(Clubs, Diamonds, Hearts, Spades)
    value <- List(Ace, Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King)
  } yield Card(suit, value, face)

}
