{-# OPTIONS_GHC -Wall -Wextra -Werror #-}

main :: IO ()
main =
    print
        . sum
        . filter (\x -> x == sumDigitFacto 0 x)
        $ [10 .. 1499999]

sumDigitFacto :: Int -> Int -> Int
sumDigitFacto acc n
    | n < 10 = acc + myFacto n
    | otherwise = sumDigitFacto (acc + myFacto (mod n 10)) (div n 10)

myFacto :: Int -> Int
myFacto = (factos !!)

factos :: [Int]
factos = [1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880]

{- {{{
   upper bound
   if n digit && n > 7 -> maximum 362880 * n < 10 ^ (n - 1)
   -> n <= 7 -> maximum 7 * 9! = 2540160
   -> n <= 2540160
   -> sumDigitFacto n <= 2 + 6 * 9! = 2177283
   -> max sumDigitFacto of 2bcdefg = 1814403 -> impossible
   -> n <= 1999999 = 1bcdefg
   -> n <= 1 + 4! + 5 * 9! = 1814425
   -> if b > 4 -> max = 1 + 8! + 4! + 4 * 9! = 1491865 < 1bcdefg
   -> n <= 1499999 -> 14cdefg 1451665
}}} -}
