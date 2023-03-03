{-# OPTIONS_GHC -Wall -Wextra -Werror #-}

import Data.Bits
import Data.Char

isPangram :: String -> Bool
isPangram = (== shiftL 1 26 - 1) . foldr fn 0
  where
    fn :: Char -> Int -> Int
    fn c acc =
        if isAlpha c
            then shiftL 1 ((ord c .|. 32) - 97) .|. acc
            else acc
