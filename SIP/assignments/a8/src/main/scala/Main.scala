object Main extends App {
  val accessToken = "EAAKyCZB4ahLcBALxxMZBLAqqlSQCRQTL26FYR1bsgvvFT1pA1yBrNrlQZBiA1iIdaGs9wLX8pZB24ahAMswAdpELtZCcCiqD9yR53wc1Y1dex6U7FI2uwEZARQRwbG4SISo7JZCGZCONkY3LqVbhdsCnwg9TEr2zU7OWpsfVhpZBZCZB8epRY0ZCAYPXbbDZBfH5phQvnzKILBAj4Ryde7HIZBGMZBT"
  val user1Id = "758714262521015"
  val user2Id = "758714262521015"
  val logFile = "./test.txt"
  val likeComparator = new LikeComparator(accessToken)

  likeComparator.compareLikes(logFile, user1Id, user2Id)
}