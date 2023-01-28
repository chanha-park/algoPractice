{-# OPTIONS_GHC -Wall -Wextra -Werror #-}

main :: IO ()
main = print . maximum . filter isPalindrome $ [x * y | x <- [100 .. 999], y <- [x .. 999]]

isPalindrome :: Int -> Bool
isPalindrome x = y == reverse y
    where
        y = show x
