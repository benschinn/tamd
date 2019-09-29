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
      Chrome.executeScript(
        [%raw{|tabs[0].id|}] : int,
        {"code": "var ing = '';
                  document.querySelector('ul.recipe-ingredients').childNodes.forEach(ele => { 
                    if(ele.innerText != undefined) {
                          ing = ing + ele.innerText + `\n`
                    }
                  })
                  var tempNode = document.createElement('textarea');
                  tempNode.value = ing;
                  document.body.appendChild(tempNode)
                  tempNode.select()
                  document.execCommand('copy')
                  tempNode.remove()
                  "
        }
      );
  });

  footer##onclick #= (() => {
    Chrome.executeScript(
      [%raw{|tabs[0].id|}] : int,
      {"code": "document.querySelector('div.nytc---shared---blackBG').style='display:none'; 
                document.querySelector('body').classList.remove('nytc---modal-window---noScroll');
                document.querySelector('html').classList.remove('nytc---modal-window---noScroll');"
      }
    )
  })
}));
