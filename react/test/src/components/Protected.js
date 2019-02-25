import React, { Component } from "react";
import {
  BrowserRouter as Router,
  Route,
  Link,
  Redirect,
  withRouter
} from "react-router-dom";
import Redirects from "./Class5";
const Public = () => {
  return (
    <div>
      <h1>Public</h1>
    </div>
  );
};
const Protect = () => {
  return (
    <div>
      <h1>Protected</h1>
    </div>
  );
};
const Change = withRouter(({ history }) => {
  return (
    <div>
      <h1>Welcome!</h1>
      <button
        onClick={() => {
          history.push("/redirects");
        }}
      >
        Sign out
      </button>
    </div>
  );
});
export default class Protected extends Component {
  render() {
    return (
      <div>
        <Router>
          {/* <ul>
<Change/>
<li><Link to='/public'>Public Page</Link></li>
<li><Link to='/protected'>Protected Page</Link></li>
<Route path="/public" component={Public}/>
<Route path="/protected" component={Protect}/>
<Route path="/redirects" component={Redirects}/>
</ul> */}
          <div>123</div>
        </Router>
      </div>
    );
  }
}
