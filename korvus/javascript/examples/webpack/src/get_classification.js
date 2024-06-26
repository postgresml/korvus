const korvus = require("korvus");

const get_classification = async (text) => {
  const builtins = korvus.newBuiltins();
  const results = await builtins.transform("text-classification", [text]);
  return results;
};

module.exports = get_classification;
