// https://mvnrepository.com/artifact/com.restfb/restfb
//libraryDependencies += "com.restfb" % "restfb" % "2023.5.0" from "file:lib/restfb-2023.5.0.jar"
//https://mvnrepository.com/artifact/com.restfb/restfb
libraryDependencies += "com.restfb" % "restfb" % "3.13.0"
//libraryDependencies += "com.restfb" % "restfb" % "2.28.0" from "file:./lib/restfb-2.28.0.jar"



val scala3Version = "2.13.4"

lazy val root = project
  .in(file("."))
  .settings(
    name := "a8",
    version := "0.1.0-SNAPSHOT",

    scalaVersion := scala3Version,

    libraryDependencies += "org.scalameta" %% "munit" % "0.7.29" % Test

)
