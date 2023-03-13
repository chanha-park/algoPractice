{-# OPTIONS_GHC -Wall -Wextra -Werror #-}

module Clock (addDelta, fromHourMin, toString) where

data Clock = Clock
    { getHour :: Int
    , getMin :: Int
    }
    deriving (Eq)

fromHourMin :: Int -> Int -> Clock
fromHourMin h m = addDelta h m (Clock 0 0)

toString :: Clock -> String
toString clock = showClock (getHour clock) <> ":" <> showClock (getMin clock)
  where
    showClock :: Int -> String
    showClock n
        | n < 10 = "0" <> show n
        | otherwise = show n

addDelta :: Int -> Int -> Clock -> Clock
addDelta h m clock =
    let newMin = m + getMin clock
     in Clock (mod (h + getHour clock + div newMin 60) 24) (mod newMin 60)
