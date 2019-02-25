import React, { Component } from "react";
import {
  BrowserRouter as Router,
  Route,
  Link,
  Switch,
  withRouter,
  Prompt,
  NavLink
} from "react-router-dom";

const Page1 = () => {
  return <div>Page1</div>;
};
const Page2 = () => {
  return <div>Page2</div>;
};

export default class Class3 extends Component {
  render() {
    return (
      <div>
        <Router>
          <div>
            <Route path="/page1" component={Page1} />
            <Route path="/page2" component={Page2} />
          </div>
        </Router>
      </div>
    );
  }
}
