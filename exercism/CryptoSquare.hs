{-# OPTIONS_GHC -Wall -Wextra -Werror #-}

module CryptoSquare (encode) where

import Data.Char
import Data.List

encode :: String -> String
encode = unwords . transpose . breakDown . map toLower . filter isAlphaNum

breakDown :: String -> [String]
breakDown xs = breakDown' r c xs
  where
    (r, c) = getRectangleLength (length xs)
    breakDown' row col ys
        | length ys > col = front : breakDown' row col back
        | otherwise = [ys ++ replicate (col - length ys) ' ']
      where
        (front, back) = splitAt col ys

getRectangleLength :: Int -> (Int, Int)
getRectangleLength n
    | isSquare n = (\x -> (x, x)) . intSquare $ n
    | isSquare (4 * n + 1) = (r, r + 1)
    | otherwise = getRectangleLength (n + 1)
  where
    r = div (intSquare (4 * n + 1) - 1) 2

isSquare :: Integral a => a -> Bool
isSquare n
    | n < 0 = False
    | n <= 1 = True
    | otherwise = isSquare' n 1 n
  where
    isSquare' k l r
        | l >= r = False
        | m * m > k = isSquare' k l m
        | m * m < k = isSquare' k (m + 1) r
        | otherwise = True
      where
        m = div (l + r) 2

intSquare :: Integral a => a -> a
intSquare n
    | n < 0 = 0
    | n <= 1 = n
    | otherwise = intSquare' n 1 1 n
  where
    intSquare' k prev l r
        | l >= r = prev
        | m * m > k = intSquare' k prev l m
        | otherwise = intSquare' k m (m + 1) r
      where
        m = div (l + r) 2
