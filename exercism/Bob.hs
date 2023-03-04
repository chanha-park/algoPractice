{-# OPTIONS_GHC -Wall -Wextra -Werror #-}

module Bob (responseFor) where

import Data.Char

responseFor :: String -> String
responseFor xs
    | all isSpace xs = "Fine. Be that way!"
    | isQuestion xs && isYell xs = "Calm down, I know what I'm doing!"
    | isQuestion xs = "Sure."
    | isYell xs = "Whoa, chill out!"
    | otherwise = "Whatever."

isQuestion :: String -> Bool
isQuestion = (== '?') . last . filter (not . isSpace)

isYell :: String -> Bool
isYell xs = all isUpper ys && not (null ys)
  where
    ys = filter isAlpha xs
