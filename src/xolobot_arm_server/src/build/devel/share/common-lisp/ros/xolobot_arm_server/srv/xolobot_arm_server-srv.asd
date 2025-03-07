
(cl:in-package :asdf)

(defsystem "xolobot_arm_server-srv"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "EvaluateDriver" :depends-on ("_package_EvaluateDriver"))
    (:file "_package_EvaluateDriver" :depends-on ("_package"))
  ))