{-# OPTIONS_GHC -Wall -Wextra #-}

module Minesweeper (annotate) where

import Data.Char

annotate :: [String] -> [String]
annotate [] = []
annotate ([] : xs) = [] : annotate xs
annotate board =
    [ [ if board !! x !! y == '*' then '*' else (if n == 0 then ' ' else intToChar n)
      | y <- [0 .. getWidth board - 1]
      , let n = countMine board x y
      ]
    | x <- [0 .. getHeight board - 1]
    ]

getHeight :: [String] -> Int
getHeight = length

getWidth :: [String] -> Int
getWidth = length . head

countMine :: [[Char]] -> Int -> Int -> Int
countMine board row col =
    length
        . filter (\(r, c) -> board !! r !! c == '*')
        . filter (\(r, c) -> r >= 0 && c >= 0 && r < getHeight board && c < getWidth board)
        $ ((,) <$> [row - 1, row, row + 1] <*> [col - 1, col, col + 1])

intToChar :: Int -> Char
intToChar = chr . (+ 48)
