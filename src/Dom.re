type t = {
  . 
  [@bs.set] "textContent": string,
  [@bs.set] "style": string,
  [@bs.meth] "append": t => unit,
  [@bs.set] "onclick": unit => unit,
};

[@bs.val] [@bs.scope "document"]
external createElement : string => t = "createElement";

[@bs.val] [@bs.scope "document"]
external getElementById : string => t = "getElementById";

