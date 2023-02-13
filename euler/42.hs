{-# OPTIONS_GHC -Wall -Wextra -Werror #-}

import Data.Char

main :: IO ()
main = do
    content <- readFile "p042_words.txt"
    print
        . length
        . filter isTriangleNum
        . map wordValue
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

wordValue :: String -> Int
wordValue = foldr ((+) . ((+ (-64)) . ord)) 0

isTriangleNum :: Int -> Bool
isTriangleNum n = isSquare (1 + 8 * n)

isSquare :: Integral t => t -> Bool
isSquare 1 = True
isSquare n = binSearch (^ (2 :: Int)) n 0 n

binSearch :: (Integral t, Ord a) => (t -> a) -> a -> t -> t -> Bool
binSearch fn target l r
    | l >= r = False
    | otherwise =
        if fn mid > target
            then binSearch fn target l mid
            else (fn mid >= target) || binSearch fn target (mid + 1) r
  where
    mid = div (l + r) 2
