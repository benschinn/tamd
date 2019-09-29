open Chrome;

addListener(() => {
  Js.log("plugin set");
  removeRules(None, () => {
    /*
    [%raw {|

      chrome.declarativeContent.onPageChanged.addRules([{
        conditions: [new chrome.declarativeContent.PageStateMatcher({
          pageUrl: {hostEquals: 'cooking.nytimes.com'},
        })
        ],
        actions: [new chrome.declarativeContent.ShowPageAction()]
      }])

    |}];
    */
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
