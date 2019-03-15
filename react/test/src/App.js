import React, { Component } from "react";
import "./App.css";
import Class1 from "./components/Class1";
import Class2 from "./components/Class2";
import Class3 from "./components/Class3";
import Class5 from "./components/Class5";
import Class6 from "./components/Class6";
import {
  BrowserRouter as Router,
  Route,
  Link,
  Switch,
  Redirect
} from "react-router-dom";

class App extends Component {
  render() {
    return (
      <div className="App">
        <Router>
          <div>
            {/* <Link to="/">Class1</Link>| */}
            {/* <Link to="/class2">Class2</Link>| */}
            {/* <Link to="/class3">Class3</Link> */}
            <Link to="/">Class5</Link>
            {/* <Link to="/class6">Class6</Link> */}
            <Switch>
              {/* <Route exact path={"/"} component={Class1} /> */}
              {/* <Route path={"/class2"} component={Class2} /> */}
              {/* <Route path={"/class3"} component={Class3} /> */}
              <Route path={"/"} component={Class5} />
              {/* <Route path={"/class6"} component={Class6} /> */}
            </Switch>
          </div>
        </Router>
      </div>
    );
  }
}

export default App;
