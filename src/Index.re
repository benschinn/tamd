open Chrome;

addListener(() => {
  Js.log("plugin set");
  removeRules(None, () => {
    addRules([|
      {
        "conditions": [|
           pageStateMatcher({ "pageUrl": {"urlContains": "nytimes"}})
        |],
        "actions": [|showPageAction()|]
      } 
    |]);
  });
});
