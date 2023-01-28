{-# OPTIONS_GHC -Wall -Wextra -Werror #-}

main :: IO ()
main = print . sum . takeWhile (< 4000000) $ evenFibo

evenFibo :: [Int]
evenFibo = evenFibo' 2 8

evenFibo' :: Num t => t -> t -> [t]
evenFibo' x y = x : evenFibo' y (x + 4 * y)
