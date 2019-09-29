type t;

type pageStateMatch = {
  .
  "pageUrl": {. "hostEquals": string }
};

type rule = {
  .
  "conditions": array(t),
  "actions": array(t)
};

type rules = array(rule);

[@bs.val] [@bs.scope ("chrome", "runtime", "onInstalled")] 
external addListener: (unit => unit) => unit = "";

[@bs.val] [@bs.scope ("chrome", "declarativeContent", "onPageChanged")] 
external removeRules: (option(unit), (unit => unit)) => unit = "";

[@bs.val] [@bs.scope ("chrome", "declarativeContent", "onPageChanged")] 
external addRules: rules => unit = "";

[@bs.new] [@bs.scope ("chrome", "declarativeContent")]
external pageStateMatcher: pageStateMatch => t = "PageStateMatcher";

[@bs.new] [@bs.scope ("chrome", "declarativeContent")]
external showPageAction: unit  => t = "ShowPageAction";
