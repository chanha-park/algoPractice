{-# OPTIONS_GHC -Wall -Wextra -Werror #-}

module Grains (square, total) where

import Data.Bits

numOfSquares :: Integer
numOfSquares = 64

square :: Integer -> Maybe Integer
square n
    | n <= 0 || n > 64 = Nothing
    | otherwise = Just (shiftL 1 (fromInteger n - 1))

total :: Integer
total = shiftL 1 (fromInteger numOfSquares) - 1
