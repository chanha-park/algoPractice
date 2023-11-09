function solution(s) {
  let answer = 0;
  function impl(str) {
    if (str == "") {
      return;
    }
    ++answer;
    const firstChar = str[0];
    let same = 1;
    let diff = 0;
    for (let i = 1; i < str.length; ++i) {
      str[i] == firstChar ? ++same : ++diff;
      if (same == diff) {
        impl(str.slice(i + 1));
        return;
      }
    }
  }
  impl(s);
  return answer;
}
