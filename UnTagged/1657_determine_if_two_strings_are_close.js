/**
 * @param {string} word1
 * @param {string} word2
 * @return {boolean}
 */
var closeStrings = function (word1, word2) {
  if (word1.length !== word2.length) {
    return false;
  }
  const wMap1 = new Map();
  const wMap2 = new Map();
  for (const ch of word1) {
    if (wMap1.has(ch)) {
      wMap1.set(ch, wMap1.get(ch) + 1);
    } else {
      wMap1.set(ch, 1);
    }
  }
  for (const ch of word2) {
    if (wMap2.has(ch)) {
      wMap2.set(ch, wMap2.get(ch) + 1);
    } else {
      wMap2.set(ch, 1);
    }
  }
  const keys1 = [...wMap1.keys()].sort().join(",");
  const keys2 = [...wMap2.keys()].sort().join(",");

  const value1 = [...wMap1.values()].sort().join(",");
  const value2 = [...wMap2.values()].sort().join(",");

  return keys1 === keys2 && value1 === value2;
};
