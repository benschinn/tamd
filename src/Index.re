open Chrome;

addListener(() => {
  Js.log("plugin set");
  removeRules(None, () => {
    addRules([|
      {
        "conditions": [|
           pageStateMatcher({ "pageUrl": {"hostEquals": "cooking.nytimes.com"}}) 
        |],
        "actions": [|showPageAction()|]
      } 
    |]);
  });
});
