import React, { Component } from "react";
import {
  BrowserRouter as Router,
  Route,
  Link,
  Redirect,
  withRouter
} from "react-router-dom";
import Protected from "./Protected";
const Public = () => {
  return (
    <div>
      <h1>Public</h1>
    </div>
  );
};

/* const Login = () => {
  return (
    <div>
      <div>
        <Change isLogin={this.props.change} />
      </div>
    </div>
  );
}; */

/* const Change = withRouter(({ history }) => {
  return (
    <div>
      <h1>You must log in to view the page at /protected</h1>
      <button
        onClick={() => {
          history.push("/protected");
        }}
      >
        Login
      </button>
    </div>
  );
}); */

class Change extends React.Component {
  constructor(props) {
    super(props);
    this.state = {
      isLogin: false
    };
  }
  Login = () => {
      this.setState({
        isLogin:true
      })
    /* return (
      <div>
        <div>
          <Change isLogin={this.props.change} />
        </div>
      </div>
    ); */
  };
  render() {
    return (
      <div>
        <h1>You must log in to view the page at /protected</h1>
        <button onClick={this.Login}>Login</button>
      </div>
    );
  }
}

export default class Redirects extends Component {
  /* constructor(props) {
    super(props);
    this.state = {
      isLogin: false
    };
  } */
  change() {
    this.setState = {
      isLogin: true
    };
  }
  render() {
    return (
      <div>
        <Router>
          <ul>
            <li style={{ display: this.state.isLogin ? "none" : "block" }}>
              <h1>You're not login</h1>
            </li>
            <li>
              <Link to="/public">Public Page</Link>
            </li>
            <li>
              <Link to="/change">Protected Page</Link>
            </li>
            <Route path="/public" component={Public} />
            <Route path="/change" component={Change} />
            <Route path="/protected" component={Protected} />
          </ul>
        </Router>
      </div>
    );
  }
}
