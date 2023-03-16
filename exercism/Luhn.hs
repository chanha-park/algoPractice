{-# OPTIONS_GHC -Wall -Wextra -Werror #-}

module Luhn (isValid) where

import Data.Char

isValid :: String -> Bool
isValid = (`all` [lengthTest, digitTest, mainTest]) . flip ($) . filter (/= ' ')

lengthTest :: String -> Bool
lengthTest = (> 1) . length

digitTest :: String -> Bool
digitTest = all isDigit

mainTest :: String -> Bool
mainTest =
    (== 0)
        . (`mod` 10)
        . sum
        . mapEven makeDouble
        . reverse
        . toIntList

toIntList :: String -> [Int]
toIntList = map (reify . read . (: []))

makeDouble :: Int -> Int
makeDouble x = if 2 * x > 9 then 2 * x - 9 else 2 * x

mapEven :: (a -> a) -> [a] -> [a]
mapEven _ [] = []
mapEven f (x : xs) = x : mapOdd f xs

mapOdd :: (t -> t) -> [t] -> [t]
mapOdd _ [] = []
mapOdd f (x : xs) = f x : mapEven f xs

reify :: Int -> Int
reify = id
