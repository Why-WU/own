import React, { Component } from "react";
import {
  BrowserRouter as Router,
  Route,
  Link,
  Redirect,
  withRouter
} from "react-router-dom";
// import Protected from "./Protected";

const ReBtn = withRouter(({ history }) =>
  fake.witchOne ? (
    <div>
      <h1>Welcome!</h1>
      <button
        onClick={() => {
          fake.out(() => history.push("/"));
          // fake.out(false);
        }}
      >
        Sign out
      </button>
    </div>
  ) : (
    <h1>You're not login</h1>
  )
);
// const PrivateRoute = ({ component: Component, ...which }) => (
//   <Router
//     {...which}
//     render={props =>
//       fake.witchOne ? (
//         <Component {...props} />
//       ) : (
//         <Redirect
//           to={{
//             whichPath: "/login",
//             state: { thisRoute: props.location }
//           }}
//         />
//       )
//     }
//   />
// );
const PrivateRoute = ({ component: Component, ...which }) =>(
    <Router
      {...which}
      render={props =>
        fake.witchOne ? (
          <Component {...props} />
        ) : (
          <Redirect
            to={{
              whichPath: "/login",
              state: { thisRoute: props.location }
            }}
          />
        )
      }
    />
  );
class Login extends React.Component {
  constructor(props) {
    super(props);
    this.state = {
      isLogin: false
    };
  }

  alogin = () => {
    fake.login(() => {
      this.setState({
        isLogin: true
      });
    });
  };
  render() {
    const { thisRoute } = this.props.location.state || {
      thisRoute: { whichPath: "/" }
    };
    const { isLogin } = this.state;
    if (isLogin) {
      return <Redirect to={thisRoute} />;
    }
    return (
      <div>
        <p>You must log in to view the page at </p>
        <button onClick={this.alogin}>Log in</button>
      </div>
    );
  }
}

const fake = {
  witchOne: false,
  login(a) {
    this.witchOne = true;
    // setTimeout(a,100)
  },
  out(a) {
    this.witchOne = false;
    // setTimeout(a,100)
  }
};

/* const Change = withRouter(({ history }) => {
  return (
    <div>
      <h1>You must log in to view the page at /protected</h1>
      <button
        onClick={() => {
          history.push("/protected");
          fake.login(true);
        }}
      >
        Login
      </button>
    </div>
  );
}); */

/* class Redirects extends Component {
  constructor(props) {
    super(props);
    this.state = {
      isLogin: false
    };
  }
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
            <li>
              <Link to="/public">Public Page</Link>
            </li>
            <li>
              <Link to="/login">Protected Page</Link>
            </li>
            <Route path="/public" component={Public} />
            <Route path="/login" component={Login} />
            <Route path="/protected" component={Protected} />
          </ul>
        </Router>
      </div>
    );
  }
} */
const Protected = () => <h3>Protected</h3>;
const Public = () => <h1>Public</h1>;

const Main = () => {
  return (
    <Router>
      <div>
        <ReBtn />
        <ul>
          <li>
            <Link to="/public">Public Page</Link>
          </li>
          <li>
            <Link to="/protected">Protected Page</Link>
          </li>
        </ul>
        <Route path="/public" component={Public} />
        <Route path="/login" component={Login} />
        <PrivateRoute path="/protected" component={Protected} />

        {/*  <PrivateRoute path="/redirects" component={Redirects} /> */}
      </div>
    </Router>
  );
};

export default Main;
