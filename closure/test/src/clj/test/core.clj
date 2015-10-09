(ns test.core
  (:require [ring.adapter.jetty :as jetty]
            [ring.middleware.resource :as resources]
            [ring.util.response :as response])
  (:gen-class))

(def ^:const port 3000)

(defn open-in-browser! [address]
  (println "Location:" address)
  (when (java.awt.Desktop/isDesktopSupported)
    (.browse (java.awt.Desktop/getDesktop) (java.net.URI. address))))

(defn handler [request]
  (response/redirect "/index.html"))

(def app (resources/wrap-resource handler "public"))

(defn -main [& args]
  (jetty/run-jetty app {:port port :join? false})
  (open-in-browser! (str "http://localhost:" port)))
