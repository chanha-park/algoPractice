{-# OPTIONS_GHC -Wall -Wextra -Werror #-}

import Data.Char
import Data.List

main :: IO ()
main = do
    content <- readFile "names.txt"
    print
        . sum
        . map (uncurry (*))
        . indexFrom 1
        . map alphaValue
        . sort
        . wordsBy (== ',')
        $ content

wordsBy :: (Char -> Bool) -> String -> [String]
wordsBy p s = case dropWhile p s of
    "" -> []
    s' -> unQuote w : wordsBy p s''
      where
        (w, s'') = break p s'

unQuote :: String -> String
unQuote = filter (/= '"')

alphaValue :: String -> Int
alphaValue = foldr ((+) . ((+ (-64)) . ord)) 0

indexFrom :: Int -> [a] -> [(Int, a)]
indexFrom _ [] = []
indexFrom n (x : xs) = (n, x) : indexFrom (n + 1) xs
