{-# OPTIONS_GHC -Wall -Wextra #-}

module SecretHandshake (handshake) where

import Data.Bits ((.&.))
import GHC.Bits (Bits)

{-
00001 = wink
00010 = double blink
00100 = close your eyes
01000 = jump
10000 = Reverse the order of the operations in the secret handshake.
-}

(&) :: (Bits a, Num a) => a -> a -> Bool
(&) a b = (a .&. b) /= 0

handshake :: Int -> [String]
handshake n
    | n & 16 = reverse $ handshake (n - 16)
    | n & 1 = "wink" : handshake (n - 1)
    | n & 2 = "double blink" : handshake (n - 2)
    | n & 4 = "close your eyes" : handshake (n - 4)
    | n & 8 = "jump" : handshake (n - 8)
    | otherwise = []
