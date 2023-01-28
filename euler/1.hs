{-# OPTIONS_GHC -Wall -Wextra -Werror #-}

main :: IO ()
main = print . sum $ [x :: Int | x <- [1 .. 999], mod x 3 == 0 || mod x 5 == 0]
