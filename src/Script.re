open Dom;

Js.log("script loaded")

[@bs.val] [@bs.scope ("window", "location")]
external pathname: string = "pathname";

[@bs.send.pipe: string] external split: string => array('a) = "";
[@bs.send.pipe: array('a)] external includes: 'a => bool = "";

Chrome.query({"active": true, "currentWindow": true}, (tabs => {
  Js.log(tabs)
  let url : string = [%raw {|tabs[0].url|}];
  let isRecipe = url |> split("/")|> includes("recipes");

  let div = getElementById("index");
  div##style #= "width: 100px; padding:10px";

  let p = createElement("p");
  p##textContent #= "The page you are viewing doesn't seem to be a recipe.";
  p##style #= "font-style: italic;";

  let button = createElement("button");
  button##textContent #= "Copy Ingredients!";
  button##style #= "font-size: 9px; margin-bottom: 10px;";

  switch(isRecipe) {
  | false => div##append(p)
  | true => div##append(button)
  }

  let footer = createElement("span");
  footer##textContent #= {js|For Laura ❤️|js};
  footer##style #= "display: block; text-align: right; font-size:10px;";
  div##append(footer);

  button##onclick #= (() => {
    Js.log("button clicked")
  });

  footer##onclick #= (() => {
    Js.log("footer clicked")
  })
}));
