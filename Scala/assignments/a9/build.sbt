val scala3Version = "3.3.0"
libraryDependencies += "org.scalactic" %% "scalactic" % "3.2.16"
libraryDependencies += "org.scalatest" %% "scalatest" % "3.2.16" % "test"

// Enable Scoverage plugin
enablePlugins(ScoverageSbtPlugin)

// Scoverage settings
coverageMinimum := 80, // Set your desired coverage threshold
coverageHighlighting := true // Enable highlighting of covered and uncovered code


lazy val root = project
  .in(file("."))
  .settings(
    name := "a9",
    version := "0.1.0-SNAPSHOT",
    scalaVersion := scala3Version,
    libraryDependencies += "org.scalameta" %% "munit" % "0.7.29" % Test
  )
